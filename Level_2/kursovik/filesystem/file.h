#ifndef FILE_H
#define FILE_H

#include "filesystem.h"

#include <cinttypes>
#include <string>
#include <vector>

namespace MyFileSystem
{
class FileSystem; // forward declaration

class MyFile
{
private:
    friend class FileSystem;

    std::string _name_file; // имя файла
    uint64_t _size_file; // размер файла
    std::vector<uint8_t> _data_file; // данные файла
    FileSystem& filesystem; // указание к какой фс принадлежит
    int _flush_flag;

    MyFile(std::string name_file, FileSystem& filesystem);

public:
//    void read(const MyFile& other);
//    void write(std::string str);
    void write(const std::string& data);
    void write_append(const std::string& data);
    void flush();
    void delete_file();
};
}

#endif // FILE_H
