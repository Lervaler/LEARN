#include "filesystem.h"

#include <algorithm>

namespace MyFileSystem
{

void func_delete_from_files_vector(MyFileSystem::MyFile& file, FileSystem& filesystem)
{
    std::string name_name_for_find = file._meta_data_file._name_file;
    auto itr = find_if(filesystem._files.begin(), filesystem._files.end(), [&name_name_for_find](const auto& element)
    {
        return element->_meta_data_file._name_file == name_name_for_find;
    });

   if(itr != filesystem._files.end())
   {
       filesystem._files.erase(itr);
   }
}

}
