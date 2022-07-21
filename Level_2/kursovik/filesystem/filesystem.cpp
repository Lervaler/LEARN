#include "filesystem.h"

#include <algorithm>
#include <bitset>
#include <iostream>
#include <fstream>
#include <stdio.h>

namespace MyFileSystem
{
FileSystem:: FileSystem(const std::string& name)
    : _name(name)
    , _size(0)
    , _data(0)
{
}

void FileSystem::create(uint64_t size)
{
    _size = size;
    _data.resize(_size);
//    std::fill(_data.begin(), _data.end(), 0);

    std::ofstream file_system(_name, std::ios::binary);
    file_system.write(reinterpret_cast<const char*>(&MAGIC_VALUE), sizeof(MAGIC_VALUE));
    file_system.write(reinterpret_cast<const char*>(&_size), sizeof(_size));
    file_system.write(reinterpret_cast<const char*>(_data.data()), _data.size());
}

bool FileSystem::read()
{
    std::ifstream file_system(_name, std::ios::binary);
    uint32_t read_magic_value;
    uint64_t read_size;
    file_system.read(reinterpret_cast<char*>(&read_magic_value), sizeof(read_magic_value));
    if(MAGIC_VALUE != read_magic_value)
    {
        return false;
    }
    file_system.read(reinterpret_cast<char*>(&read_size), sizeof(read_size));
    _data.resize(read_size);
    file_system.read(reinterpret_cast<char*>(_data.data()), _data.size());
    return true;
}

void FileSystem::destroy()
{
    std::remove(_name.c_str());
}

MyFileSystem::MyFile  FileSystem::create_file(std::string name_file)
{
    MyFileSystem::MyFile file(std::move(name_file), *this);
    std::cout << "enter data" <<std::endl;
    std::string enter{};
    std::cin >> enter;

    for( char c : enter)
      {
          std::bitset<8> bs(c);
          file._data_file.emplace_back(bs.to_ulong());
      }
std::cout << file._data_file.data() <<std::endl;
return file;

//    _data.emplace_back(new MyFileSystem::MyFile(std::move(name_file), *this));
//    _data.data();
//    return _data.back();
//    return _data.data();
}

void FileSystem::flush_file(const MyFile& file)
{
    std::ofstream file_system(this->_name, std::ios::binary);

//    file_system.write(reinterpret_cast<const char*>(&MAGIC_VALUE), sizeof(MAGIC_VALUE));
//    file_system.write(reinterpret_cast<const char*>(&_size), sizeof(_size));
     file_system.seekp(12, std::ios::beg);
//    fseek(*file_system, 12, SEEK_SET);
    file_system.write(reinterpret_cast<const char*>(file._data_file.data()), file._data_file.size());
}


}
