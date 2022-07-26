#include "gtest/gtest.h"
#include "../../filesystem.h"
#include "../../file.h"

#include <filesystem>
#include <string>

TEST (Filesystem_test, create_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";

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

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(1024*4, fs_name);

    auto file_1 = sys_1.create_file("hello");
    auto file_2 = sys_1.create_file("world");
    file_1->write("aaaaaaaa", 8);
    file_2->write("bbbbbbbb", 8);
    file_1->flush();
    file_2->flush();


}






















