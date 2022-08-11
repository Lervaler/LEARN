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
class MyFile;

class FileSystem
{
private:
    std::string _name; // имя файловой системы (файл .fs)
    MetaData _meta_data; // метаданные файловой системы - основные характеристики
    MetaDataFiles _meta_data_files;

    std::vector<std::shared_ptr<MyFile>> _files; // данные файлов в фс
    std::array<uint8_t, BLOCK_MAX*BLOCK_SIZE> _data; // BLOCK_SIZE*BLOCK_MAX+ metadata

    FileSystem(const std::string& name);
    bool read();

public:
    static FileSystem create(std::string name); // создание файловой системы
    void destroy();// уничтожение файловой системы

    std::shared_ptr<MyFileSystem::MyFile> create_file(std::string name_file); // создание файла
    void rename_file(MyFileSystem::MyFile& file, std::string new_name ); // переименование
    void flush_file(const MyFileSystem::MyFile& file); // запись файла в фс
    void delete_file(MyFileSystem::MyFile& file); // удалить файла из фс
};
}

#endif // FILESYSTEM_H
