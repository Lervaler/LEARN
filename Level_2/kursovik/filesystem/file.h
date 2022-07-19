#ifndef FILE_H
#define FILE_H
#include <string>
#include <vector>
#include <cinttypes>
#include "filesystem.h"


class MyFile
{
private:
    std::string _name_file;
    std::vector<uint8_t> _size_file;
    std::string _data_file;
public:
    MyFile(const std::string name);

    void read(const MyFile& other);
    void write(MyFile& other, std::string str);
//    void flush(MyFileSystem::FileSystem& other, const MyFile& other_file);

};


#endif // FILE_H
