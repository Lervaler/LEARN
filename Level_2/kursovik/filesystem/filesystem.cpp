#include "filesystem.h"

#include <algorithm>
#include <bitset>
#include <cstdio>
#include <exception>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace
{
    constexpr size_t Max_size_of_file = 124;
}

namespace MyFileSystem
{
FileSystem::FileSystem(const std::string& name)
    : _name(name)
{}

FileSystem FileSystem::create(uint64_t size, std::string name)
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
        uint64_t capasity = size;
        filesystem._meta_data = {MAGIC_VALUE, size, {}, capasity};
//        filesystem._files.resize(size);
        std::ofstream file_system(filesystem._name, std::ios::binary);
        filesystem._meta_data.write(file_system);
//        file_system.write(reinterpret_cast<const char*>(filesystem._files.data()), filesystem._files.size());
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
    _meta_data._files_offset[file->_name_file] = Max_size_of_file * _files.size();
    _files.push_back(file);
//    std::ofstream file_system(_name, std::ios_base::in);
//    _meta_data.write(file_system);

    return file;
}

void FileSystem::flush_file(const MyFileSystem::MyFile& file)
{
    std::ofstream file_system(_name, std::ios_base::in);
    if(file._flush_flag > 0 && file._flush_flag < 2)
   {
        uint64_t temp_capasity = _meta_data._capasity;
        _meta_data._capasity = temp_capasity - Max_size_of_file;
        _meta_data.write(file_system);
    }
    file_system.seekp(sizeof(_meta_data) + _meta_data._files_offset[file._name_file], std::ios::beg);
    file_system.write(reinterpret_cast<const char*>(file._data_file.data()), file._data_file.size());
}

void FileSystem::delete_file(MyFileSystem::MyFile& file)
{
    std::ofstream file_system(_name, std::ios_base::in|std::ios_base::out);
    file_system.seekp(sizeof(_meta_data) + _meta_data._files_offset[file._name_file], std::ios::beg);

    file._data_file.erase(file._data_file.begin(), file._data_file.end());

    file_system.write(reinterpret_cast<const char*>(file._data_file.data()), file._data_file.size());

    file_system.seekp(std::ios::beg);
    _meta_data._files_offset.erase(file._name_file);
    _meta_data._capasity = _meta_data._capasity + Max_size_of_file;
    _meta_data.write(file_system);

}

}
