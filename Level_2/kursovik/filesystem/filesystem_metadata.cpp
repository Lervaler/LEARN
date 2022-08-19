#include "filesystem_metadata.h"

namespace MyFileSystem
{

MetaData::MetaData()
: _magic_value(MAGIC_VALUE)
{
    std::fill(_free_space.begin(), _free_space.end(), FREE_BLOCK);
    std::fill(_fat_tab.begin(), _fat_tab.end(), EMPTY_FAT);
}

bool MetaData::read(std::istream& stream)
{
    uint32_t magic_value = 0;
    stream.read(reinterpret_cast<char*>(&magic_value), sizeof(magic_value));
    if(magic_value != MAGIC_VALUE)
        return false;

    _magic_value = magic_value;
    stream.read(reinterpret_cast<char*>(_free_space.data()), _free_space.size());
    stream.read(reinterpret_cast<char*>(_fat_tab.data()), _fat_tab.size());

    return stream.good();
}

bool MetaData::write(std::ostream& stream)
{
    stream.write(reinterpret_cast<const char*>(&_magic_value), sizeof(_magic_value));
    stream.write(reinterpret_cast<const char*>(_free_space.data()), _free_space.size());
    stream.write(reinterpret_cast<const char*>(_fat_tab.data()), _fat_tab.size());

    return stream.good();
}

size_t MetaData::size() const
{
    return sizeof(_magic_value) + _free_space.size()*sizeof(bool) + _fat_tab.size()*sizeof(uint32_t);
}

}
