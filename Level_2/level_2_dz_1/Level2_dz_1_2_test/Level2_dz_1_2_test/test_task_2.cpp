#include <gtest/gtest.h>
#include <iostream>
#include "search.h"

using namespace std;

TEST (TEST_SWAP, TEST_6)
{
    vector <int> nums = {0};
    int result = 0;
    result = search(nums);

    EXPECT_EQ(result, 0);
}

TEST (TEST_SWAP, TEST_5)
{
    vector <int> nums = {4, 3, 3, 2, 2};
    int result = 0;
    result = search(nums);

    EXPECT_EQ(result, 4);
}

TEST (TEST_SWAP, TEST_4)
{
    vector <int> nums = {1,3,1,-1,3};
    int result = 0;
    result = search(nums);

    EXPECT_EQ(result, -1);
}

TEST (TEST_SWAP, TEST_3)
{
    vector <int> nums = {1, 0, 1};
    int result = 0;
    result = search(nums);

    EXPECT_EQ(result, 0);
}

TEST (TEST_SWAP, TEST_2)
{
    vector <int> nums = {2, 2, 1};
    int result = 0;
    result = search(nums);

    EXPECT_EQ(result, 1);
}

TEST (TEST_SWAP, TEST_1)
{
    vector <int> nums = {4,1,2,1,2};
    int result = 0;
    result = search(nums);

    EXPECT_EQ(result, 4);
}


