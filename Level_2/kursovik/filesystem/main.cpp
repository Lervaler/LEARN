#include <iostream>
#include "filesystem.h"
#include "file.h"
#include <bitset>
#include<cstring>
int main()
{



    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\tree.fs";
    MyFileSystem::FileSystem sys_1(fs_name);
    sys_1.create(4*1024);

   MyFileSystem::MyFile file = sys_1.create_file("hello");
   sys_1.flush_file(file);


    return 0;
}
