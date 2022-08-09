#ifndef FILESYSTEM_METADATA_H
#define FILESYSTEM_METADATA_H

#include "sign.h"

#include <cinttypes>
#include <iostream>
#include <string>
#include <unordered_map>

namespace MyFileSystem
{
    struct MetaData
    {
        uint32_t _magic_value = 0; // магическое число
        std::array<bool, BLOCK_MAX> _free_space; //свободно - занято
        std::array<uint32_t , BLOCK_MAX> _fat_tab; // таблица индексов

        MetaData();

        bool read(std::istream& stream);
        bool write(std::ostream& stream);
        size_t size() const;
    };
}

#endif // FILESYSTEM_METADATA_H
