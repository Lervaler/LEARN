#ifndef SIGN_H
#define SIGN_H

#include <cinttypes>

namespace MyFileSystem
{
    enum TypeSpace
    {
        FREE_BLOCK = 1,
        BUSY_BLOCK = 0,
        END_BLOCK = -1,
        EMPTY_FAT = 0
    };

    static constexpr uint32_t MAGIC_VALUE = 785; // магическое число
    static constexpr uint64_t BLOCK_SIZE = 24; // размер одного блока
    static constexpr uint64_t BLOCK_MAX = 240; // размер всех блоков = поместится 100 блоков

    constexpr size_t Max_size_of_file = 124;
}

#endif // SIGN_H
