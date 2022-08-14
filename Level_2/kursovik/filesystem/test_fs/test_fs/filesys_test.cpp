#include "gtest/gtest.h"
#include "../../filesystem.h"
#include "../../file.h"

#include <filesystem>
#include <string>

TEST (Filesystem_test, create_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    EXPECT_FALSE(std::filesystem::exists(fs_name));

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);

    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    auto file_2 = sys_1.create_file("world");
    file_1->write("aaabbbcccdddfffggghhhjjjkkk");
    file_1->flush();
    file_2->write("qqq www eee");
    file_2->flush();
    file_1->write("ooooo ooooo ooooo oooooo ooooo ooooo ooooo ooooo ooooo ooooo oooooo oooooo ooooo oooooo oooooo");
    file_1->flush();
//    sys_1.destroy();
//    EXPECT_FALSE(std::filesystem::exists(fs_name));
}
//
//TEST (Filesystem_test, read_test)
//{
//    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
//                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";
//    {
//        MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(1024*4, fs_name);
//    }
//
//    MyFileSystem::FileSystem sys_2 = MyFileSystem::FileSystem::create(1024*4, fs_name);
//
//    sys_2.destroy();
//}
//
//TEST (Filesystem_test, write_file)
//{
//    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
//                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";
//
//    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(124*4, fs_name);
//
//    auto file_1 = sys_1.create_file("hello");
//    auto file_2 = sys_1.create_file("world");
//    file_1->write("aa");
//    file_2->write("bb");
//    file_1->flush();
//    file_2->flush();
//    auto file_3 = sys_1.create_file("new_file");
//    file_3->write("nanana");
//    file_3->flush();


//    file_1->delete_file();
//}






















