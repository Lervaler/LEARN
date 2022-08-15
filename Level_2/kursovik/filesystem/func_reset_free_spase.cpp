#include "filesystem.h"

namespace MyFileSystem
{

void func_reset_free_spase(const std::vector<uint32_t>& current_file_indexes, FileSystem& filesystem)
{
    for(int64_t i = 0; i < current_file_indexes.size(); ++i)
    {
        for(int64_t j = 0; j < filesystem._meta_data._free_space.size(); ++j)
        {
            if(filesystem._meta_data._free_space[j] == BUSY_BLOCK)
            {
                filesystem._meta_data._free_space[j] = FREE_BLOCK;
                break;
            }
        }
    }
}

}
