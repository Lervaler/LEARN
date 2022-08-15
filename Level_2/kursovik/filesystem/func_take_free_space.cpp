#include "filesystem.h"

namespace MyFileSystem
{

void func_take_free_space(int64_t blocks_max, FileSystem& filesystem)
{
    for(int64_t i = 0; i < blocks_max; ++i)
    {
        for(int64_t j = 0; j < filesystem._meta_data._free_space.size(); ++j)
        {
            if(filesystem._meta_data._free_space[j] == FREE_BLOCK)
            {
                filesystem._meta_data._free_space[j] = BUSY_BLOCK;
                break;
            }
        }
    }
}

}
