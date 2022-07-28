#include "filesystem_metadata.h"

namespace MyFileSystem
{

bool MetaData::read(std::istream& steam)
{
    uint32_t magic_value = 0;
    steam.read(reinterpret_cast<char*>(&magic_value), sizeof(magic_value));
    if(magic_value != MAGIC_VALUE)
        return false;

    _magic_value = magic_value;

    steam.read(reinterpret_cast<char*>(&_size), sizeof(_size));
    size_t table_size = 0;

    steam.read(reinterpret_cast<char*>(&table_size), sizeof(table_size));
    for (size_t i = 0; i < table_size; ++i)
    {
        size_t key_size = 0;
        steam.read(reinterpret_cast<char*>(&key_size), sizeof(key_size));
        std::string temp_key;
        temp_key.resize(key_size);
        steam.read(reinterpret_cast<char*>(temp_key.data()), key_size);
        size_t temp_value = 0;
        steam.read(reinterpret_cast<char*>(&temp_value), sizeof(temp_value));
        _files_offset[temp_key] = temp_value;
    }
    steam.read(reinterpret_cast<char*>(&_capasity), sizeof(_capasity));

    return steam.good();
}

bool MetaData::write(std::ostream& steam)
{
    steam.write(reinterpret_cast<const char*>(&_magic_value), sizeof(_magic_value));
    steam.write(reinterpret_cast<const char*>(&_size), sizeof(_size));
    size_t table_size = _files_offset.size();
    steam.write(reinterpret_cast<const char*>(&table_size), sizeof(table_size));
    for (const auto& [key, value]: _files_offset)
    {
        size_t key_size = key.size();
//        steam.write(reinterpret_cast<const char*>(&key_size), sizeof(key_size));
        steam.write(reinterpret_cast<const char*>(key.data()), key_size);
        steam.write(reinterpret_cast<const char*>(&value), sizeof(value));
    }
    steam.write(reinterpret_cast<const char*>(&_capasity), sizeof(_capasity));

    return steam.good();
}

size_t MetaData::size() const
{
}

}
