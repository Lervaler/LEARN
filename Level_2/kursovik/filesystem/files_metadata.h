#ifndef FILES_METADATA_H
#define FILES_METADATA_H

#include "file_metadata.h"

#include <string>
#include <unordered_map>

namespace MyFileSystem
{

struct MetaDataFiles
{
    std::unordered_map<std::string, MetaDataFile> _files_meta_data;

    MetaDataFiles();

    bool write(std::ostream& stream);
};
}
#endif // FILES_METADATA_H
