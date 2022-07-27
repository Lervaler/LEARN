#include "gtest/gtest.h"
#include "../../filesystem.h"
#include "../../file.h"

#include <filesystem>
#include <string>

TEST (Filesystem_test, create_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ojj.fs";

    EXPECT_FALSE(std::filesystem::exists(fs_name));

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(1024*4, fs_name);

    EXPECT_TRUE(std::filesystem::exists(fs_name));

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, read_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";
    {
        MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(1024*4, fs_name);
    }

    MyFileSystem::FileSystem sys_2 = MyFileSystem::FileSystem::create(1024*4, fs_name);

    sys_2.destroy();
}

TEST (Filesystem_test, write_file)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(124, fs_name);

    auto file_1 = sys_1.create_file("hellou");
    auto file_2 = sys_1.create_file("wordddddd");
    file_1->write("la la la land");
    file_2->write("bbbbbbbb");
    file_1->flush();
    file_2->flush();
    auto file_3 = sys_1.create_file("new_file");
    file_3->write("nanana");
    file_3->flush();
    file_1->write("new-lala");
    file_1->flush();
}





















