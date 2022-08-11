#include "files_metadata.h"
#include <iterator>
#include <ostream>
//    std::unordered_map<std::string, MetaDataFile> _files_meta_data;

namespace MyFileSystem
{
MetaDataFiles::MetaDataFiles()
{
}

bool MetaDataFiles::read(std::istream &stream)
{
    return true;
}

bool MetaDataFiles::write(std::ostream& stream)
{
//    size_t table_size = _files_meta_data.size();
//    stream.write(reinterpret_cast<const char*>(&table_size), sizeof(table_size));
    for (const auto& [key, value]: _files_meta_data)
    {
        stream.write(reinterpret_cast<const char*>(key.data()), key.size());
        stream.write(reinterpret_cast<const char*>(&value._fat_index), sizeof(value._fat_index));
        stream.write(reinterpret_cast<const char*>(&value._size_file), sizeof(value._size_file));
    }
    return stream.good();
}

size_t MetaDataFiles::size() const
{

}
}
