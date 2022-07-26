#include "filesystem.h"

#include <algorithm>
#include <bitset>
#include <exception>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdio>

namespace
{
    constexpr size_t Max_size_of_file = 1024;
}

namespace MyFileSystem
{
FileSystem::FileSystem(const std::string& name)
    : _name(name)
//    , _data(0)
{
}

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
        filesystem._meta_data = {MAGIC_VALUE, size, {}};
        std::ofstream file_system(filesystem._name, std::ios::binary);
        filesystem._meta_data.write(file_system);
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
    std::ofstream file_system(_name, std::ios_base::in);
    _meta_data.write(file_system);

    return file;
}

void FileSystem::flush_file(const MyFileSystem::MyFile& file)
{
    std::ofstream file_system(_name, std::ios_base::in);

    file_system.seekp(sizeof(_meta_data) + _meta_data._files_offset[file._name_file], std::ios::beg);

    file_system.write(reinterpret_cast<const char*>(file._name_file.data()), file._name_file.size());
    file_system.write(reinterpret_cast<const char*>(file._data_file.data()), file._data_file.size());
}


}
