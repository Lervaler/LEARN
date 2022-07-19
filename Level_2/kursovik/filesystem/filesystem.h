#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "file.h"

#include <cinttypes>
#include <string>
#include <vector>

// create read delete

namespace MyFileSystem
{
class FileSystem
{
private:
    static constexpr uint32_t MAGIC_VALUE = 785;

    std::vector<uint8_t> _ptr;
    std::string _name;
    uint64_t _size;

public:
    FileSystem(const std::string& name);

    void create(uint64_t size);
    bool read();
    void destroy();
};
}

#endif // FILESYSTEM_H
