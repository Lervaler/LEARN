#include "filesystem.h"

namespace MyFileSystem
{

void func_make_fat_indexing(MyFileSystem::MyFile& file, int64_t blocks_max, FileSystem& filesystem)
{
    for(uint64_t i = 0; i < filesystem._meta_data._fat_tab.size(); ++i)
    {
        if(filesystem._meta_data._fat_tab[i] == EMPTY_FAT)
        {
            filesystem._meta_data._fat_tab[i] = END_BLOCK;
            file._meta_data_file._fat_index = i;
            break;
        }
    }

    int64_t index = file._meta_data_file._fat_index;

    for(int64_t i = 0; i < blocks_max - 1 && blocks_max > 1; ++i)
    {
        for(int64_t j = 0; j < filesystem._meta_data._fat_tab.size(); ++j)
       {
            if(filesystem._meta_data._fat_tab[j] == EMPTY_FAT )
            {
                filesystem._meta_data._fat_tab[index] = j;
                index = j;
                break;
            }
        }
        filesystem._meta_data._fat_tab[index] = END_BLOCK;
    }
}

}
