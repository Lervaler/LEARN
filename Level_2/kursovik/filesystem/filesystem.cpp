#include "filesystem.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdio.h>

namespace MyFileSystem
{
FileSystem:: FileSystem(const std::string& name)
    : _name(name)
    , _size(0)
{
}

void FileSystem::create(uint64_t size)
{
    _size = size;
    _ptr.resize(_size);
    std::fill(_ptr.begin(), _ptr.end(), 0);

    std::ofstream file_system(_name, std::ios::binary);
    file_system.write(reinterpret_cast<const char*>(&MAGIC_VALUE), sizeof(MAGIC_VALUE));
    file_system.write(reinterpret_cast<const char*>(&_size), sizeof(_size));
    file_system.write(reinterpret_cast<const char*>(_ptr.data()), _ptr.size());
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
    _ptr.resize(read_size);
    file_system.read(reinterpret_cast<char*>(_ptr.data()), _ptr.size());
    return true;
}

void FileSystem::destroy()
{
    std::remove(_name.c_str());
}

}
