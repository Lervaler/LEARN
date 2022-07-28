#include "file.h"

#include <bitset>
#include <cstring>
#include <iostream>

namespace
{
    constexpr size_t Max_size_of_file = 124;
}

namespace MyFileSystem
{
MyFile::MyFile(std::string name_file, FileSystem& filesystem)
    : _name_file(std::move(name_file))
    , _size_file(0)
    , _data_file(0)
    , filesystem(filesystem)
    , _flush_flag(0)
{}

void MyFile::write(const std::string& data)
{
    if (sizeof(data) <= Max_size_of_file)
    {
        _data_file.resize(data.size());
        memcpy(_data_file.data(), data.data(), data.size());
        _size_file = data.size();
        ++_flush_flag;
    }
    else throw std::exception{};
}

void MyFile::write_append(const std::string& data)
{
    _flush_flag = 0;
    if(!_data_file.empty())
    {
        if (sizeof(data) <= Max_size_of_file + _size_file)
        {
            const uint64_t temp_data = _data_file.size();
            _data_file.resize(temp_data + data.size());
            memcpy(_data_file.data() + temp_data, data.data(), data.size());
            _size_file = data.size();
        }
        else throw std::exception{};
    }
    else throw std::exception{};
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
