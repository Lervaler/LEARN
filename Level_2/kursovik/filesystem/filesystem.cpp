#include "filesystem.h"

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <exception>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

namespace MyFileSystem
{
FileSystem::FileSystem(const std::string& name)
    : _name(name)
{
}

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
       filesystem._meta_data._fat_tab[0] = RESERVED_FAT;
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
    std::shared_ptr<MyFileSystem::MyFile>file {new MyFileSystem::MyFile{std::move(name_file), *this} };
    _files.push_back(file);

    return file;
}

void FileSystem::rename_file(MyFileSystem::MyFile& file, std::string new_name)
{
}

void FileSystem::flush_file(const MyFileSystem::MyFile& file)
{

// считаем сколько блоков памяти займет файл
    int64_t blocks_max = (file._meta_data_file._size_file/ BLOCK_SIZE) + 1; // кол-во блоков памяти для файла
//    int64_t blocks_max = (file._data_file.size()/ BLOCK_SIZE) + 1; // кол-во блоков памяти для файла


    // присваиваем индексы, запоминаем метаданные

    if (file._meta_data_file._fat_index != 0)// если файл уже был записан и уже есть индексы (0 блок ФАТ-таблицы зарезервирован)
    {
        // сначала считать индексы которые были - и обнулить их, зачистить свободное место по количеству блоков

        uint32_t first_index = file._meta_data_file._fat_index; // первый фат-индекс в файле

        std::vector<uint32_t> current_file_indexes; // все фат-индексы текущего файла
        current_file_indexes.emplace_back(file._meta_data_file._fat_index);
        uint32_t i = first_index;
        for ( ; _meta_data._fat_tab.at(i) != END_BLOCK;)
        {
            current_file_indexes.emplace_back(_meta_data._fat_tab.at(i));
            i = _meta_data._fat_tab.at(i);
        }

        for(uint32_t i = 0; i < current_file_indexes.size(); ++i)
        {
                    _meta_data._fat_tab[current_file_indexes.at(i)] = EMPTY_FAT;
        }

        for(int64_t i = 0; i < current_file_indexes.size(); ++i)
        {
            for(int64_t j = 0; j < _meta_data._free_space.size(); ++j)
            {
                if(_meta_data._free_space[j] == BUSY_BLOCK)
                {
                    _meta_data._free_space[j] = FREE_BLOCK;
                    break;
                }
            }
        }
        file._meta_data_file._fat_index = 0;
        //перезаписать метадату
        std::ofstream file_system(_name, std::ios_base::in);
        file_system.seekp(0, std::ios::beg);
        _meta_data.write(file_system);
    }


    if (file._meta_data_file._fat_index == 0)   // если это новый файл ранее не записывался на диск
    {
        for(uint64_t i = 0; i < _meta_data._fat_tab.size(); ++i)
        {
            if(_meta_data._fat_tab[i] == EMPTY_FAT)
            {
                _meta_data._fat_tab[i] = END_BLOCK;
                file._meta_data_file._fat_index = i;
                break;
            }
        }

        int64_t index = file._meta_data_file._fat_index;

        for(int64_t i = 0; i < blocks_max - 1 && blocks_max > 1; ++i)
        {
            for(int64_t j = 0; j < _meta_data._fat_tab.size(); ++j)
           {
                if(_meta_data._fat_tab[j] == EMPTY_FAT )
                {
                    _meta_data._fat_tab[index] = j;
                    index = j;
                    break;
                }
            }
            _meta_data._fat_tab[index] = END_BLOCK;
        }


        for(int64_t i = 0; i < blocks_max; ++i)
        {
            for(int64_t j = 0; j < _meta_data._free_space.size(); ++j)
            {
                if(_meta_data._free_space[j] == FREE_BLOCK)
                {
                    _meta_data._free_space[j] = BUSY_BLOCK;
                    break;
                }
            }
        }

        _meta_data_files._files_meta_data[file._meta_data_file._name_file] = file._meta_data_file;

    }
//    _meta_data_files._files_meta_data.emplace(file._meta_data_file._name_file, file._meta_data_file);



// записываем на диск метадату и метадату файлов

    std::ofstream file_system(_name, std::ios_base::in);

    file_system.seekp(0, std::ios::beg);
    _meta_data.write(file_system);

    file_system.seekp(_meta_data.size(), std::ios::beg);
    _meta_data_files.write(file_system);


// запись на диск данных


    // списываем с фат-таблицы индексы для текущего файла
    uint32_t first_index = file._meta_data_file._fat_index; // первый фат-индекс в файле

    std::vector<uint32_t> current_file_indexes; // все фат-индексы текущего файла
    current_file_indexes.emplace_back(file._meta_data_file._fat_index);
    uint32_t i = first_index;
    for (; _meta_data._fat_tab.at(i) != END_BLOCK;)
    {
        current_file_indexes.emplace_back(_meta_data._fat_tab.at(i));
        i = _meta_data._fat_tab.at(i);
    }

    //запись
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

void FileSystem::delete_file(MyFileSystem::MyFile& file)
{

}

}
