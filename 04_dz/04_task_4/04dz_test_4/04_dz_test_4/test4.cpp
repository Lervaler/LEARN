#include "gtest/gtest.h"
#include "../../04_task_4/part_task_4.h"

TEST( TestTask4, Test_1)
{
    int Mass[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int res = 0;
    res = part_task_4((int*)Mass, 2, 3);

    EXPECT_EQ( res, 1);
}

TEST( TestTask4, Test_2)
{
    int Mass[0][0];

    int res = 0;
    res = part_task_4((int*)Mass, 0, 0);

    EXPECT_EQ( res, 0);
}

TEST( TestTask4, Test_3)
{
    int Mass[2][3] = { {-1, 2, 3}, {4, 5, 6} };

    int res = 0;
    res = part_task_4((int*)Mass, 2, 3);

    EXPECT_EQ( res, -1);
}
