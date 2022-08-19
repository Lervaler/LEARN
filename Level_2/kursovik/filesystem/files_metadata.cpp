#include "files_metadata.h"
#include "sign.h"

#include <iterator>
#include <ostream>

namespace MyFileSystem
{

MetaDataFiles::MetaDataFiles()
{}

bool MetaDataFiles::write(std::ostream& stream)
{
    for (const auto& [key, value]: _files_meta_data)
    {
        stream.write(reinterpret_cast<const char*>(key.data()), key.size()); // sizeof(Max_size_of_name_file)
        stream.write(reinterpret_cast<const char*>(&value._fat_index), sizeof(value._fat_index));
        stream.write(reinterpret_cast<const char*>(&value._size_file), sizeof(value._size_file));
    }
    return stream.good();
}

}
