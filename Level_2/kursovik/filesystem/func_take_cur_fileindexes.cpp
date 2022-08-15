#include "filesystem.h"

namespace MyFileSystem
{

std::vector<uint32_t> func_take_cur_fileindexes(const MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem)
{
    uint32_t first_index = file._meta_data_file._fat_index; // первый фат-индекс в файле
    std::vector<uint32_t> current_file_indexes; // сюда положим все фат-индексы текущего файла
    current_file_indexes.emplace_back(file._meta_data_file._fat_index);// добавим первый фат-индекс в файле

    uint32_t i = first_index;
    for ( ; filesystem._meta_data._fat_tab.at(i) != END_BLOCK;)
    {
        current_file_indexes.emplace_back(filesystem._meta_data._fat_tab.at(i));
        i = filesystem._meta_data._fat_tab.at(i);
    }
    return current_file_indexes;
}

}
