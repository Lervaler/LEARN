#include "gtest/gtest.h"
#include "../../04_task_5/part1.h"

TEST (Test_dz_4_task_5, test1)

{
    const char* str = "qqq ww eeee r";
    const char* result_str = "ww eeee";
char result[50];
part1 (str, result);

EXPECT_STREQ((char*)&result, result_str);

}
