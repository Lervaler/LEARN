#include "gtest/gtest.h"
#include "../../COW/My_string.h"

TEST(MYStringTests, CreateTest)
{
    My::String object_1("Hello");
    EXPECT_STREQ(object_1.c_str(), "Hello");
}

TEST(MYStringTests, CopyTest)
{
    My::String object_1("Hello");
    My::String object_2(object_1);
    EXPECT_STREQ(object_1.c_str(), object_2.c_str());
}

TEST(MYStringTests, AppendTest)
{
    My::String object_1("Hello");
    object_1.append(" World");
    EXPECT_STREQ(object_1.c_str(), "Hello World");
}

TEST(MYStringTests, CopyAppendTest_1)
{
    My::String object_1("Hello");
    My::String object_2(object_1);

    object_1.append(" World_1");
    EXPECT_STREQ(object_1.c_str(), "Hello World_1");
    EXPECT_STREQ(object_2.c_str(), "Hello");

    object_2.append(" World_2");
    EXPECT_STREQ(object_1.c_str(), "Hello World_1");
    EXPECT_STREQ(object_2.c_str(), "Hello World_2");
}

TEST(MYStringTests, CopyAppendTest_2)
{
    My::String object_1("Hello");
    My::String object_2(object_1);

    object_2.append(" World_2");
    EXPECT_STREQ(object_1.c_str(), "Hello");
    EXPECT_STREQ(object_2.c_str(), "Hello World_2");

    object_1.append(" World_1");
    EXPECT_STREQ(object_1.c_str(), "Hello World_1");
    EXPECT_STREQ(object_2.c_str(), "Hello World_2");
}
