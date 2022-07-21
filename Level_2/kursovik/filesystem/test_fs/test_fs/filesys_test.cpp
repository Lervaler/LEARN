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

    MyFileSystem::FileSystem sys_1(fs_name);
    sys_1.create(4*1024);

    EXPECT_TRUE(std::filesystem::exists(fs_name));

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, read_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";
    {
        MyFileSystem::FileSystem sys_1(fs_name);
        sys_1.create(4*1024);
    }

    MyFileSystem::FileSystem sys_2(fs_name);
    EXPECT_TRUE( sys_2.read());
    sys_2.destroy();
}

TEST (Filesystem_test, file_create_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\tree.fs";
    MyFileSystem::FileSystem sys_1(fs_name);
    sys_1.create(4*1024);
//    sys_1.create_file("hello");
    sys_1.create_file("hello");
//    EXPECT_EQ(data, "o");


}


