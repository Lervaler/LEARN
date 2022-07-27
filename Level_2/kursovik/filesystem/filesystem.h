#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "file.h"
#include "filesystem_metadata.h"

#include <cinttypes>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace MyFileSystem
{
class MyFile;

class FileSystem
{
private:


    std::string _name;
    MetaData _meta_data;
    std::vector<std::shared_ptr<MyFile>> _files; //для записи файлов

    FileSystem(const std::string& name);
    bool read();

public:

    static FileSystem create(uint64_t size, std::string name);
    void destroy();

    std::shared_ptr<MyFile> create_file(std::string name_file);
    void flush_file(const MyFileSystem::MyFile& file);

};
}

#endif // FILESYSTEM_H
