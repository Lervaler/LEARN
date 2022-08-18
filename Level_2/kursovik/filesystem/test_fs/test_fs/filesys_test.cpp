#include "gtest/gtest.h"
#include "../../filesystem.h"
#include "../../file.h"

#include <filesystem>
#include <string>
#include <vector>

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

TEST (Filesystem_test, write_file_without_flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    file_1->write("aaabbb");

    std::vector<uint8_t> a = file_1->read();
    std::vector<uint8_t> b = {{'a'}, {'a'} , {'a'}, {'b'}, {'b'}, {'b'}};

    EXPECT_EQ(a, b);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, write_append_file_without_flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    file_1->write("aaabbb");

    std::vector<uint8_t> a = file_1->read();
    std::vector<uint8_t> b = {{'a'}, {'a'} , {'a'}, {'b'}, {'b'}, {'b'}};

    EXPECT_EQ(a, b);

    file_1->write_append("ccc");
    std::vector<uint8_t> a_a = file_1->read();
    b.push_back('c');
    b.push_back('c');
    b.push_back('c');

    EXPECT_EQ(a_a, b);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, rename_without_flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    std::string name = "hello";
    auto file_1 = sys_1.create_file(name);
    std::string old_name = file_1->name_return();
    EXPECT_EQ(name, old_name);

    std::string new_name = "world";
    file_1->rename(new_name);
    std::string new_name_file = file_1->name_return();
    EXPECT_EQ(new_name, new_name_file);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, rename_after_flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    std::string name = "hello";
    auto file_1 = sys_1.create_file(name);

    std::string a = file_1->name_return();
    EXPECT_EQ(name, a);

    file_1->write("aaabbb");
    file_1->flush();

    MyFileSystem::MyFile file_a = sys_1.read_from_disk(*file_1);

    std::string file_1_name = file_1->name_return();
    std::string file_a_name = file_a.name_return();
    EXPECT_EQ(file_1_name, file_a_name);

    std::vector<uint8_t> file_1_data = file_1->read();
    std::vector<uint8_t> file_a_data = file_a.read();
    EXPECT_EQ(file_1_data, file_a_data);

    std::string new_name = "world";
    file_1->rename(new_name);

    std::string new_name_file = file_1->name_return();
    EXPECT_EQ(new_name, new_name_file);

    MyFileSystem::MyFile file_b = sys_1.read_from_disk(*file_1);

    std::string file_new_name = file_1->name_return();
    std::string file_b_name = file_b.name_return();
    EXPECT_EQ(file_new_name, file_b_name);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}


TEST (Filesystem_test, flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    file_1->write("aaabbb");
    file_1->flush();

    MyFileSystem::MyFile file_a = sys_1.read_from_disk(*file_1);

    std::string file_1_name = file_1->name_return();
    std::string file_a_name = file_a.name_return();
    EXPECT_EQ(file_1_name, file_a_name);


    std::vector<uint8_t> file_1_data = file_1->read();
    std::vector<uint8_t> file_a_data = file_a.read();
    EXPECT_EQ(file_1_data, file_a_data);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));

}



//file_1->flush();

//    auto file_2 = sys_1.create_file("world");
//    auto file_3 = sys_1.create_file("file2");

//    file_2->write("qqq www www");
//    file_2->flush();
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
//    sys_1.read_file(*file_1);


