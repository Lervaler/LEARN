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
        std::unordered_map<std::string, size_t> files_offset; // ограничить размер строки?
        files_offset.rehash(size/Max_size_of_file);
        filesystem._meta_data = {MAGIC_VALUE, size, files_offset, capasity};
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
    _meta_data._capasity = _meta_data._capasity - Max_size_of_file;
    std::ofstream file_system(_name, std::ios_base::in);
    _meta_data.write(file_system);
    return file;
}

void FileSystem::rename_file(MyFileSystem::MyFile& file)
{

}

void FileSystem::flush_file(const MyFileSystem::MyFile& file)
{
    if(_meta_data._capasity >= Max_size_of_file)
    {
        std::ofstream file_system(_name, std::ios_base::in);
        file_system.seekp(sizeof(_meta_data) + _meta_data._files_offset[file._name_file], std::ios::beg);
        file_system.write(reinterpret_cast<const char*>(file._data_file.data()), file._data_file.size());
    }
    else throw std::exception{};
}

void FileSystem::delete_file(MyFileSystem::MyFile& file)
{
    // нужно будет проверять был ли флаш? делать сдвиг всего, что после удаляемого файла?
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
