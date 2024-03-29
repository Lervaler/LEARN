#ifndef FILE_METADATA_H
#define FILE_METADATA_H

#include <string>

namespace MyFileSystem
{
struct MetaDataFile
{
    friend struct MetaDataFiles;

    std::string _name_file; // имя файла
    uint64_t _size_file; // размер файла
    mutable uint32_t _fat_index; // фат-индекс по умолчанию в конструкторе выставится в зарезервированную ячейку

    void read();
    void write();
    size_t size() const;
};
}
#endif // FILE_METADATA_H
