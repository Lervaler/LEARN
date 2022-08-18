#ifndef FILE_H
#define FILE_H

#include "filesystem.h"
#include "file_metadata.h"

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
    friend struct MetaDataFiles;

    MetaDataFile _meta_data_file;
    std::vector<uint8_t> _data_file; // данные файла
    FileSystem& filesystem; // указание к какой фс принадлежит

    MyFile(std::string name_file, FileSystem& filesystem);

public:
    friend void func_fat_indexing(const MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem);
    friend std::vector<uint32_t> func_take_cur_fileindexes(const MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem);
    friend void func_make_fat_indexing(MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem);
    friend void func_delete_from_files_vector(MyFileSystem::MyFile& file, FileSystem& filesystem);

    void write(const std::string& data);
    void write_append(const std::string& data);
    void rename(std::string new_name);
    void flush();
    void read();
    void delete_file();
};
}

#endif // FILE_H
