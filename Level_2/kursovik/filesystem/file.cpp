#include "file.h"

#include <bitset>
#include <cstring>
#include <iostream>

namespace MyFileSystem
{
MyFile::MyFile(std::string name_file, FileSystem& filesystem)
    : _data_file(0)
    , filesystem(filesystem)
{
    _meta_data_file._name_file = std::move(name_file);
    _meta_data_file._size_file = 0;
    _meta_data_file._fat_index = 0;
}

void MyFile::write(const std::string& data)
{
//    if (data.size() <= Max_size_of_file)
//    {
        _data_file.resize(data.size());
        memcpy(_data_file.data(), data.data(), data.size());
        _meta_data_file._size_file = data.size();
//    }
//    else throw std::exception{};
}

void MyFile::write_append(const std::string& data)
{
    const uint64_t temp_data = _data_file.size();
    _data_file.resize(temp_data + data.size());
    memcpy(_data_file.data() + temp_data, data.data(), data.size());
    _meta_data_file._size_file = _data_file.size();
}

void MyFile::rename(std::string new_name)
{
    filesystem.rename_file(*this, new_name);
}

void MyFile::flush()
{
    filesystem.flush_file(*this);
}

void MyFile::delete_file()
{
    filesystem.delete_file(*this);

}

}
