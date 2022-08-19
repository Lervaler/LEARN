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

TEST (Filesystem_test, create_2_test)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\one.fs";
    {
        MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    }
    MyFileSystem::FileSystem sys_2 = MyFileSystem::FileSystem::create(fs_name);
    sys_2.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, write_file_without_flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    file_1->write("aaabbb");

    std::vector<uint8_t> file_a = file_1->read();
    std::vector<uint8_t> compare = {'a', 'a' , 'a', 'b', 'b', 'b'};

    EXPECT_EQ(file_a, compare);

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

    MyFileSystem::MyFile file_a = sys_1.read_from_files(*file_1);

    std::string file_1_name = file_1->name_return();
    std::string file_a_name = file_a.name_return();
    EXPECT_EQ(file_1_name, file_a_name);

    std::vector<uint8_t> file_1_data = file_1->read();
    std::vector<uint8_t> file_a_data = file_a.read();
    EXPECT_EQ(file_1_data, file_a_data);

    std::vector<uint8_t> file_disk = sys_1.read_data_from_disk("hello");
    std::vector<uint8_t> compare = {'a', 'a' , 'a', 'b', 'b', 'b'};
    EXPECT_EQ(file_disk, compare);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, write_file_after_flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    file_1->write("aaabbb");
    file_1->flush();

    std::vector<uint8_t> compare = {'a', 'a' , 'a', 'b', 'b', 'b'};

    MyFileSystem::MyFile file_from_md = sys_1.read_from_files(*file_1);
    std::vector<uint8_t> file_disk_data = file_from_md.read();
    EXPECT_EQ(compare, file_disk_data);

    std::vector<uint8_t> file_disk = sys_1.read_data_from_disk("hello");
    EXPECT_EQ(file_disk, compare);

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

    std::vector<uint8_t> file_a = file_1->read();
    std::vector<uint8_t> compare = {'a', 'a' , 'a', 'b', 'b', 'b'};

    EXPECT_EQ(file_a, compare);

    file_1->write_append("ccc");
    std::vector<uint8_t> file_a_a = file_1->read();
    compare.push_back('c');
    compare.push_back('c');
    compare.push_back('c');

    EXPECT_EQ(file_a_a, compare);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, write_append_file_after_flush)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    file_1->write("aaabbb");
    file_1->flush();
    file_1->write_append("ccc");
    file_1->flush();

    MyFileSystem::MyFile file_from_md = sys_1.read_from_files(*file_1);

    std::vector<uint8_t> file_1_data = file_1->read();
    std::vector<uint8_t> file_md_data = file_from_md.read();
    EXPECT_EQ(file_1_data, file_md_data);

    std::vector<uint8_t> compare = {'a', 'a' , 'a', 'b', 'b', 'b', 'c', 'c', 'c'};
    EXPECT_EQ(compare, file_md_data);

    std::vector<uint8_t> file_disk = sys_1.read_data_from_disk("hello");
    EXPECT_EQ(file_disk, compare);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, name)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    std::string name = "hello";
    auto file_1 = sys_1.create_file(name);

    MyFileSystem::MyFile file_from_mdf = sys_1.read_from_files(*file_1);

    std::string file_1_name = file_1->name_return();
    std::string file_from_mdf_name = file_from_mdf.name_return();

    EXPECT_EQ(file_1_name, file_from_mdf_name);
    EXPECT_EQ(file_1_name, name);
    EXPECT_EQ(file_from_mdf_name, name);

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

    MyFileSystem::MyFile file_a = sys_1.read_from_files(*file_1);

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

    MyFileSystem::MyFile file_b = sys_1.read_from_files(*file_1);

    std::string file_new_name = file_1->name_return();
    std::string file_b_name = file_b.name_return();
    EXPECT_EQ(file_new_name, file_b_name);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, two_files)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    auto file_2 = sys_1.create_file("world");

    file_1->write("aaa bbb ccc");
    file_1->flush();
    file_2->write("www www www");
    file_2->flush();

    std::vector<uint8_t> file_1_disk = sys_1.read_data_from_disk("hello");
    std::vector<uint8_t> compare_1 = {'a', 'a' , 'a', ' ', 'b', 'b', 'b', ' ', 'c', 'c', 'c'};
    EXPECT_EQ(file_1_disk, compare_1);

    std::vector<uint8_t> file_2_disk = sys_1.read_data_from_disk("world");
    std::vector<uint8_t> compare_2 = {'w', 'w' , 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w' , 'w'};
    EXPECT_EQ(file_2_disk, compare_2);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, tree_files)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    auto file_2 = sys_1.create_file("world");
    auto file_3 = sys_1.create_file("tree");

    file_1->write("aaa bbb ccc");
    file_1->flush();
    file_2->write("www www www");
    file_2->flush();
    file_3->write("rrr rrr rrr");
    file_3->flush();

    std::vector<uint8_t> file_1_disk = sys_1.read_data_from_disk("hello");
    std::vector<uint8_t> compare_1 = {'a', 'a' , 'a', ' ', 'b', 'b', 'b', ' ', 'c', 'c', 'c'};
    EXPECT_EQ(file_1_disk, compare_1);

    std::vector<uint8_t> file_2_disk = sys_1.read_data_from_disk("world");
    std::vector<uint8_t> compare_2 = {'w', 'w' , 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w' , 'w'};
    EXPECT_EQ(file_2_disk, compare_2);

    std::vector<uint8_t> file_3_disk = sys_1.read_data_from_disk("tree");
    std::vector<uint8_t> compare_3 = {'r', 'r' , 'r', ' ', 'r', 'r', 'r', ' ', 'r', 'r' , 'r'};
    EXPECT_EQ(file_3_disk, compare_3);

    sys_1.destroy();
    EXPECT_FALSE(std::filesystem::exists(fs_name));
}

TEST (Filesystem_test, two_files_long_append)
{
    static const std::string fs_name = "D:\\01_Projects\\HomeWork\\"
                                       "LEARN\\LEARN\\Level_2\\kursovik\\filesystem\\ONE.fs";

    MyFileSystem::FileSystem sys_1 = MyFileSystem::FileSystem::create(fs_name);
    EXPECT_TRUE(std::filesystem::exists(fs_name));

    auto file_1 = sys_1.create_file("hello");
    auto file_2 = sys_1.create_file("world");

    file_1->write("aaa bbb ccc");
    file_1->flush();
    file_2->write("www www www");
    file_2->flush();
    file_1->write_append("sss sss sss sss sss sss sss sss");
    file_1->flush();

    std::vector<uint8_t> file_1_disk = sys_1.read_data_from_disk("hello");
    std::vector<uint8_t> compare_1 = {'a', 'a' , 'a', ' ', 'b', 'b', 'b', ' ', 'c', 'c', 'c',
                                      's', 's' , 's', ' ', 's', 's', 's', ' ', 's', 's', 's', ' ',
                                      's', 's' , 's', ' ', 's', 's', 's', ' ', 's', 's', 's', ' ',
                                      's', 's' , 's', ' ', 's', 's', 's'};
    EXPECT_EQ(file_1_disk, compare_1);

    std::vector<uint8_t> file_2_disk = sys_1.read_data_from_disk("world");
    std::vector<uint8_t> compare_2 = {'w', 'w' , 'w', ' ', 'w', 'w', 'w', ' ', 'w', 'w' , 'w'};
    EXPECT_EQ(file_2_disk, compare_2);

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


