#ifndef FILESYSTEM_METADATA_H
#define FILESYSTEM_METADATA_H

#include <cinttypes>
#include <iostream>
#include <string>
#include <unordered_map>

namespace MyFileSystem
{
    static constexpr uint32_t MAGIC_VALUE = 785;

    struct MetaData
    {
        uint32_t _magic_value = 0;
        uint64_t _size = 0;
        std::unordered_map<std::string, size_t> _files_offset;

        bool read(std::istream& steam);
        bool write(std::ostream& steam);
        size_t size() const;
    };
}

#endif // FILESYSTEM_METADATA_H
