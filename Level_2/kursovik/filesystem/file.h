#ifndef FILE_H
#define FILE_H

#include "filesystem.h"

#include <cinttypes>
#include <string>
#include <vector>

namespace MyFileSystem
{
class FileSystem;

class MyFile
{
private:
    friend class FileSystem;

    std::string _name_file;
    uint64_t _size_file;
    std::vector<uint8_t> _data_file;
    FileSystem& filesystem;

    MyFile(std::string name_file, FileSystem& filesystem);

public:
//    void read(const MyFile& other);
//    void write(std::string str);
    void write(const std::string& data);
    void flush();

};
}

#endif // FILE_H
