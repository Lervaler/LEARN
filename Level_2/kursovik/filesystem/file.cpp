#include "file.h"
#include <iostream>
#include <bitset>
#include<cstring>

MyFile::MyFile(const std::string name)
    : _name_file(name)
     ,_size_file(0)
     ,_data_file(0)
{
}

void MyFile::read(const MyFile& other)
{
//    std::cout <<"name of file: "<< other._name_file <<std::endl
//              <<"file: "<< other._data_file <<std::endl;
}

void MyFile::write(MyFile& other, std::string str)
{
    other._data_file = str;
}

//void MyFile::flush(MyFileSystem::FileSystem& other, const MyFile& other_file)
//{
////    std::memcpy(other._ptr, other_file._data_file, other_file._data_file.size());
//
//    for(uint8_t i = 0; i < other_file._data_file.size(); ++i)
//    {
//        std::bitset<8> new_ch(other_file._data_file.at(i));
//        uint8_t a = uint8_t(new_ch.to_ullong());
//        std::memcpy(&other._ptr.at(i), a, a);
//    }
//}


