#include "gtest/gtest.h"
#include "../../04_task_5/part1.h"

TEST (Test_dz_4_task_5, test1)

{
    const char* str = "qqq ww eeee r";
    const char* result_str = "ww eeee ";
    char result[255] = {};

    part1(str, result);

EXPECT_STREQ(result, result_str);
}

TEST (Test_dz_4_task_5, test2)

{
    const char* str = " ";
    const char* result_str = " ";
    char result[255] = {};

    part1(str, result);

EXPECT_STREQ(result, result_str);
}

TEST (Test_dz_4_task_5, test3)

{
    const char* str = "111 11";
    const char* result_str = "11 ";
    char result[255] = {};

    part1(str, result);

EXPECT_STREQ(result, result_str);
}
