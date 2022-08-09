#ifndef FILES_METADATA_H
#define FILES_METADATA_H

#include "file_metadata.h"

#include <string>
#include <unordered_map>

//class MyFile;
namespace MyFileSystem
{

struct MetaDataFiles
{
//    friend class MyFile;
    std::unordered_map<std::string, MetaDataFile> _files_meta_data;

    MetaDataFiles();

    bool read(std::istream& stream);
    bool write(std::ostream& stream);
    size_t size() const;
};

}
#endif // FILES_METADATA_H
