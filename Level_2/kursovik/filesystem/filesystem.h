#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "file.h"
#include "file_metadata.h"
#include "filesystem_metadata.h"
#include "files_metadata.h"

#include <cinttypes>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace MyFileSystem
{
class MyFile; // forward declaration

class FileSystem
{
private:
    std::string _name; // имя файловой системы (файл .fs)
    MetaData _meta_data; // метаданные файловой системы - основные характеристики
    MetaDataFiles _meta_data_files; // метаданные всех файлов

    std::vector<std::shared_ptr<MyFile>> _files; // данные файлов в фс (объекты файлов - сами не пишутся на диск, только данные)

    std::array<uint8_t, BLOCK_MAX*BLOCK_SIZE> _disk_mdfiles; // место под метадату файлов на диске
    std::array<uint8_t, BLOCK_MAX*BLOCK_SIZE> _data; // место под данные файлов на диске

    FileSystem(const std::string& name);
    bool read();

public:
    friend void func_fat_indexing(const MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem);
    friend std::vector<uint32_t> func_take_cur_fileindexes(const MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem);
    friend void func_reset_free_spase(const std::vector<uint32_t>& current_file_indexes, FileSystem& filesystem);
    friend void func_make_fat_indexing(MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem);
    friend void func_take_free_space(int64_t blocks_max, FileSystem& filesystem);
    friend void func_delete_from_files_vector(MyFileSystem::MyFile& file, FileSystem& filesystem);

    static FileSystem create(std::string name); // создание файловой системы
    void destroy();// уничтожение файловой системы

    std::shared_ptr<MyFileSystem::MyFile> create_file(std::string name_file); // создание файла
    void rename_file(MyFileSystem::MyFile& file, std::string new_name ); // переименование
    void flush_file(MyFileSystem::MyFile& file); // запись файла в фс
    void show_data_file_from_disk(MyFileSystem::MyFile& file); // прочитать файл
    void delete_file(MyFileSystem::MyFile& file); // удалить файла из фс
    MyFileSystem::MyFile read_from_files(MyFileSystem::MyFile& file);
    std::vector<uint8_t> read_data_from_disk(std::string name_file);
    bool existing_file(std::string name_file);
};
}

#endif // FILESYSTEM_H
