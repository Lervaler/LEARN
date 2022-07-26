#include "file.h"
#include <iostream>
#include <bitset>
#include<cstring>

namespace MyFileSystem {

MyFile::MyFile(std::string name_file, FileSystem& filesystem)
    : _name_file(std::move(name_file))
    , _size_file(0)
    , _data_file(0)
    , filesystem(filesystem)
{}

//void MyFileSystem::MyFile::read(const MyFile& other)
//{
//    std::cout <<"name of file: "<< other._name_file <<std::endl
//              <<"file: "<< other._data_file <<std::endl;
//}

//void MyFileSystem::MyFile::write(MyFile& other, std::string str)
//{
//    other._data_file = str;
//}

void MyFile::write(const void* data, size_t size)
{
    const size_t temp_size = _data_file.size();
    _data_file.resize(temp_size + size);
    memcpy(_data_file.data()+ temp_size, data, size);
}

void MyFile::flush()
{
    filesystem.flush_file(*this);
}

}
