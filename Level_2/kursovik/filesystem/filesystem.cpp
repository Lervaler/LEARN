#include "filesystem.h"

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <exception>
#include <iostream>
#include <ostream>
#include <fstream>
#include <filesystem>
#include <vector>

namespace MyFileSystem
{
FileSystem::FileSystem(const std::string& name)
    : _name(name)
{}

FileSystem FileSystem::create(std::string name)
{
    FileSystem filesystem(std::move(name));

    if(std::filesystem::exists(name))
    {
        if(filesystem.read() == false)
        {
            throw std::exception{};
        }
    }
    else
    {
       filesystem._disk_mdfiles.fill(META_DATA_FREE); // заполнение данных
       filesystem._data.fill(FREE_DATA); // заполнение данных
       filesystem._meta_data._fat_tab[0] = RESERVED_FAT; // первая ячейка индекса в резерве для незафлашеных файлов
       filesystem._meta_data._fat_tab[1] =  DELETED_FAT; // вторая ячейка индекса в резерве для удаленных файлов
        std::ofstream file_system(filesystem._name, std::ios::binary);

        file_system.seekp(0, std::ios::beg);
        filesystem._meta_data.write(file_system);

        file_system.write(reinterpret_cast<const char*>(filesystem._disk_mdfiles.data()), filesystem._disk_mdfiles.size());
        file_system.write(reinterpret_cast<const char*>(filesystem._data.data()), filesystem._data.size());
    }
    return filesystem;
}

bool FileSystem::read()
{
    std::ifstream file_system(_name, std::ios::binary);
    return _meta_data.read(file_system);
}

void FileSystem::destroy()
{
    std::remove(_name.c_str());
}

std::shared_ptr<MyFileSystem::MyFile> FileSystem::create_file(std::string name_file)
{
    // проверка на название файла - чтобы не повторялись

    std::string name_name_for_find = name_file;
    auto itr = find_if(_files.begin(), _files.end(), [&name_name_for_find](const auto& element)
    {
        return element->_meta_data_file._name_file == name_name_for_find;
    });

   if(itr == _files.end())
   {
       std::shared_ptr<MyFileSystem::MyFile>file {new MyFileSystem::MyFile{std::move(name_file), *this} };
       _files.push_back(file);
       return file;
   }
    else throw std::exception{};
}

void FileSystem::rename_file(MyFileSystem::MyFile& file, std::string new_name)
{
    if(file._meta_data_file._fat_index != 1)
    {
        if (file._meta_data_file._fat_index != 0) // если уже был зафлашен
        {
            // замена имени в unordered_map метадате-файлов
            auto it = _meta_data_files._files_meta_data.find(file._meta_data_file._name_file);
            if (it != _meta_data_files._files_meta_data.end())
            {
              _meta_data_files._files_meta_data[new_name] = it->second;
              _meta_data_files._files_meta_data.erase(it);
            }
            // забираем имя в метадату файла
            file._meta_data_file._name_file = std::move(new_name);
            //перезаписываем на диске имя
            std::ofstream file_system(_name, std::ios_base::in);
            file_system.seekp(_meta_data.size(), std::ios::beg);
            _meta_data_files.write(file_system);
        }

        else // если просто создан и не зафлашен
        {
            file._meta_data_file._name_file = std::move(new_name);
        }
    }
    else
    {
        std::cout << "you can't rename this" << std::endl;
    }
}

void FileSystem::flush_file(MyFileSystem::MyFile& file)
{
    if(file._meta_data_file._fat_index != 1)
    {
        // считаем сколько блоков памяти займет файл
        int64_t blocks_max = (file._meta_data_file._size_file/ BLOCK_SIZE) + 1; // кол-во блоков памяти для файла

        if (file._meta_data_file._fat_index != 0)// если файл уже был записан и уже есть индексы (0 блок ФАТ-таблицы зарезервирован)
        {
            // сначала считать индексы которые были - и обнулить их, зачистить свободное место по количеству блоков
            // считываем текущие фат-индексы файла
            std::vector<uint32_t> current_file_indexes = func_take_cur_fileindexes(file, blocks_max, *this);

            // освобождение фат-таблицы от текущих индексов
            for(uint32_t i = 0; i < current_file_indexes.size(); ++i)
            {
                 _meta_data._fat_tab[current_file_indexes.at(i)] = EMPTY_FAT;
            }

            // освобождение свободного места
             func_reset_free_spase(current_file_indexes, *this);

            // обнуление фат-индекса файла (указатель на зарезервированную часть фат-таблицы)
            file._meta_data_file._fat_index = 0;
        }

        if (file._meta_data_file._fat_index == 0)   // если это новый файл ранее не записывался на диск
        {
            // присваиваем фат-индексы файлу
            func_make_fat_indexing(file, blocks_max, *this); // из-за изменений в индексах пришлось снять константность flush

            // занимаем место в таблице свободного места
            func_take_free_space(blocks_max, *this);

            // добавляем в метадату всех файлов объект текущего файла (ключ - имя, содержимое - размер и фат-индекс)
            _meta_data_files._files_meta_data[file._meta_data_file._name_file] = file._meta_data_file;
        }

        // записываем на диск метадату и метадату файлов
        std::ofstream file_system(_name, std::ios_base::in);

        file_system.seekp(0, std::ios::beg);
        _meta_data.write(file_system);

        file_system.seekp(_meta_data.size(), std::ios::beg);
        _meta_data_files.write(file_system);

        // списываем с фат-таблицы индексы файла
        std::vector<uint32_t> current_file_indexes = func_take_cur_fileindexes(file, blocks_max, *this);

        //запись на диск данных
        uint8_t k = 0;
        for(uint8_t j = 0; j < blocks_max; ++j)
        {
            file_system.seekp(_meta_data.size()+ _disk_mdfiles.size()+ BLOCK_SIZE*current_file_indexes.at(j), std::ios::beg);
            for(uint8_t i = 0; i < BLOCK_SIZE && k < file._data_file.size(); ++i)
            {
                file_system.write(reinterpret_cast<const char*>(&file._data_file[k]), sizeof(i));
                ++k;
            }
        }
    }
    else
    {
        std::cout << "you can't flush this" << std::endl;
    }
}

void FileSystem::show_data_file_from_disk(MyFileSystem::MyFile& file) // from _files
{
    if(file._meta_data_file._fat_index != 1)
    {
        std::string name_name_for_find = file._meta_data_file._name_file;
        auto itr = find_if(_files.begin(), _files.end(), [&name_name_for_find](const auto& element)
        {
            return element->_meta_data_file._name_file == name_name_for_find;
        });

        int a = 0;
        if(itr != _files.end())
        {
            a = std::distance(_files.begin(), itr);
        }

        MyFile file_a = (* _files[a]);

        for(std::vector<uint8_t>::iterator it = file_a._data_file.begin() ; it!=file_a._data_file.end() ; ++it)
        {
            std::cout<<*it;
        }
    }
    else
    {
        std::cout << "you can't read this" << std::endl;
    }
}


void FileSystem::delete_file(MyFileSystem::MyFile& file)
{
    if(file._meta_data_file._fat_index != 0 && file._meta_data_file._fat_index != 1)
    {
        int64_t blocks_max = (file._meta_data_file._size_file/ BLOCK_SIZE) + 1;
        // считываем текущие фат-индексы файла
        std::vector<uint32_t> current_file_indexes = func_take_cur_fileindexes(file, blocks_max, *this);

        // освобождение фат-таблицы от текущих индексов
        for(uint32_t i = 0; i < current_file_indexes.size(); ++i)
        {
             _meta_data._fat_tab[current_file_indexes.at(i)] = EMPTY_FAT;
        }

        // освобождение свободного места
         func_reset_free_spase(current_file_indexes, *this);
         file._meta_data_file._fat_index = 1; // флаг удаленного

         // удаляем файл из вектора всех файлов
          func_delete_from_files_vector(file, *this);

        // удаляем файл из метадаты файлов
        auto it = _meta_data_files._files_meta_data.find(file._meta_data_file._name_file);
        if (it != _meta_data_files._files_meta_data.end())
        {
            _meta_data_files._files_meta_data.erase(it);
        }

        // перезаписать данные на диске
        std::ofstream file_system(_name, std::ios_base::in);
        file_system.seekp(0, std::ios::beg);
        _meta_data.write(file_system);
        file_system.seekp(_meta_data.size(), std::ios::beg);
        _meta_data_files.write(file_system);
    }

     if(file._meta_data_file._fat_index == 0)
     {
        // удаляем файл из вектора всех файлов
         func_delete_from_files_vector(file, *this);
     }

     else
     {
         std::cout<<"you can't delete deleted file"<< std:: endl;
     }
}

MyFileSystem::MyFile FileSystem::read_from_files(MyFileSystem::MyFile& file)
{
    std::string name_name_for_find = file._meta_data_file._name_file;
    auto itr = find_if(_files.begin(), _files.end(), [&name_name_for_find](const auto& element)
    {
        return element->_meta_data_file._name_file == name_name_for_find;
    });

    int a = 0;
    if(itr != _files.end())
    {
        a = std::distance(_files.begin(), itr);
    }

    MyFile file_a = (* _files[a]);

    for(std::vector<uint8_t>::iterator it = file_a._data_file.begin() ; it!=file_a._data_file.end() ; ++it)
    {
        std::cout<<*it;
    }
    return file_a;
}

std::vector<uint8_t> FileSystem::read_data_from_disk(std::string name_file)
{
    std::string name_name_for_find = std::move(name_file);
    auto itr = find_if(_files.begin(), _files.end(), [&name_name_for_find](const auto& element)
    {
        return element->_meta_data_file._name_file == name_name_for_find;
    });

    int a = 0;
    if(itr != _files.end())
    {
        a = std::distance(_files.begin(), itr);

        MyFile file_a = (* _files[a]);

        uint64_t size = file_a._meta_data_file._size_file;

        int64_t blocks_max = (size/ BLOCK_SIZE) + 1;
        std::vector<uint32_t> current_file_indexes = func_take_cur_fileindexes(file_a, blocks_max, *this);

        std::ifstream file_system(_name, std::ios::binary);

        std::vector<uint8_t> data;
        data.resize(size);

        uint8_t k = 0;
        for(uint8_t j = 0; j < blocks_max; ++j)
        {
            file_system.seekg(_meta_data.size()+ _disk_mdfiles.size()+ BLOCK_SIZE*current_file_indexes.at(j), std::ios::beg);
            for(uint8_t i = 0; i < BLOCK_SIZE && k < size; ++i)
            {
                file_system.read(reinterpret_cast<char*>(&data[k]), sizeof(i));
                ++k;
            }
        }
        return data;
    }
    else throw std::exception{};
}

bool FileSystem::existing_file(std::string name_file)
{
    std::string name_name_for_find = std::move(name_file);
    auto itr = find_if(_files.begin(), _files.end(), [&name_name_for_find](const auto& element)
    {
        return element->_meta_data_file._name_file == name_name_for_find;
    });

    int a = true;
    if(itr == _files.end())
    {
        a = false;
    }
    return a;
}

}
