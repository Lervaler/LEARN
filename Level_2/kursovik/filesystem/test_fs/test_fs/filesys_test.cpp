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

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);

    EXPECT_TRUE(std::filesystem::exists(fs_name));

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, read_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";
    {
        MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    }

    MyFileSystem::FileSystem sys_2 = MyFileSystem::FileSystem::create(fs_name);

    sys_2.destroy();
}

TEST (Filesystem_test, write_file)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);

    auto file_1 = sys_1.create_file("hello");
    auto file_2 = sys_1.create_file("world");
    auto file_3 = sys_1.create_file("file2");
    file_1->write("aaabbb");
    file_1->flush();
    file_2->write("qqq www www");
    file_2->flush();
//    file_1->write("ooooo ooooo ");
//    file_1->flush();
//    file_1->write_append("eee");
//    file_1->flush();

//    sys_1.rename_file(*file_1, "new_name");

//   std::vector <uint8_t> read = sys_1.read_file(*file_1);
//   std::cout << read.data() << std::endl;

//    file_1->delete_file();
//    file_3->write("ffffffffffffffffff");
//    file_3->flush();
    sys_1.read_file(*file_1);

}






















