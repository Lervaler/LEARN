#include "file.h"
#include <iostream>
#include <bitset>
#include<cstring>


namespace
{
    constexpr size_t Max_size_of_file = 124;
}

namespace MyFileSystem {

MyFile::MyFile(std::string name_file, FileSystem& filesystem)
    : _name_file(std::move(name_file))
    , _size_file(0)
    , _data_file(0)
    , filesystem(filesystem)
{}

void MyFile::write(const std::string& data)
{
    if (sizeof(data) <= Max_size_of_file)
    {
        const size_t temp_size = _data_file.size();
        _data_file.resize(temp_size + data.size());
        if(_data_file.size()<=Max_size_of_file)
        {
            memcpy(_data_file.data() + temp_size, data.data(), data.size());
        }
        else throw std::exception{};
    }
    else throw std::exception{};
}

void MyFile::flush()
{
    filesystem.flush_file(*this);
}

}
