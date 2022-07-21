#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "file.h"

#include <cinttypes>
#include <memory>
#include <string>
#include <vector>

namespace MyFileSystem
{
class MyFile;

class FileSystem
{
private:
    static constexpr uint32_t MAGIC_VALUE = 785;

    std::string _name;
    uint64_t _size;
//    std::vector<uint8_t> _ptr; //для FAT талицы
    std::vector<std::shared_ptr<MyFile>> _data; //для записи файлов


public:
    FileSystem(const std::string& name);

    void create(uint64_t size);
    bool read();
    void destroy();

    MyFileSystem::MyFile  create_file(std::string name_file);
    void flush_file(const MyFile& file);

};
}

#endif // FILESYSTEM_H
