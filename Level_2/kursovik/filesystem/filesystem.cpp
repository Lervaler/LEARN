#include "filesystem.h"

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <exception>
#include <iostream>
#include <fstream>
#include <filesystem>

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
       filesystem._data.fill(2); // заполнение данных двойками
        std::ofstream file_system(filesystem._name, std::ios::binary);

        int64_t blocks_max = (filesystem._meta_data_files._files_meta_data.size()/ BLOCK_SIZE) + 1; // кол-во байт метаданных файлика / блок
        for(int64_t i = 0; i < blocks_max; ++i)
        {
//            filesystem._meta_data._free_space[i] = BUSY_BLOCK;
            filesystem._meta_data._fat_tab[i] = i+1;
        }
        filesystem._meta_data._fat_tab[blocks_max - 1] = END_BLOCK;
//!
        file_system.seekp(0, std::ios::beg);
        filesystem._meta_data.write(file_system);

        filesystem._meta_data_files.write(file_system);

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

    for(uint64_t i = 0; i < _meta_data._free_space.size(); ++i)
    {
        if(_meta_data._free_space[i] == FREE_BLOCK)
        {
            _meta_data._free_space[i] = BUSY_BLOCK;
            _meta_data._fat_tab[i] = END_BLOCK;
            file->_meta_data_file._fat_index = i;
            break;
        }
    }
    _meta_data_files._files_meta_data.emplace(file->_meta_data_file._name_file, file->_meta_data_file);
//    _meta_data_files._files_meta_data[file->_meta_data_file._name_file] = file->_meta_data_file;

    _files.push_back(file);
    std::ofstream file_system(_name, std::ios::in);
    file_system.seekp(0, std::ios::beg);
    _meta_data.write(file_system);
    _meta_data_files.write(file_system);

//    std::ofstream file_system(_name, std::ios_base::in);

    return file;
}

void FileSystem::rename_file(MyFileSystem::MyFile& file, std::string new_name)
{
}

void FileSystem::flush_file(const MyFileSystem::MyFile& file)
{
    int64_t blocks_max = (file._data_file.size()/ BLOCK_SIZE) + 1; // кол-во байт метаданных файлика / блок

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

    int64_t index = file._meta_data_file._fat_index;

    for(int64_t i = 0; i < blocks_max; ++i)
    {
        for(int64_t j = 0; j < _meta_data._fat_tab.size(); ++j)
       {
            if(_meta_data._fat_tab[j] == 0)
            {
                _meta_data._fat_tab[index] = j;
                index = j;
                break;
            }
        }
    }
    _meta_data._fat_tab[index] = END_BLOCK;

    std::ofstream file_system(_name, std::ios_base::in);
    file_system.seekp(0, std::ios::beg);
    _meta_data.write(file_system);

//        filesystem._meta_data_files.write(file_system);

    file_system.seekp(sizeof(_meta_data) + sizeof(_meta_data_files), std::ios::beg);
    file_system.write(reinterpret_cast<const char*>(file._data_file.data()), file._data_file.size());
}

void FileSystem::delete_file(MyFileSystem::MyFile& file)
{
}

}
