#include <gtest/gtest.h>
#include "../../Level_2_dz_1/swap.h"
#include <iostream>
using namespace std;


TEST (TEST_SWAP, TEST_9)
{
    EXPECT_TRUE(swap_string("abab", "abab"));
}


TEST (TEST_SWAP, TEST_6)
{
    EXPECT_FALSE(swap_string("abcd", "abcd"));
}

TEST (TEST_SWAP, TEST_10)
{
    EXPECT_TRUE(swap_string("accccb", "bcccca"));
}


TEST (TEST_SWAP, TEST_1)
{
    EXPECT_FALSE(swap_string("ab", "ab"));
}

TEST (TEST_SWAP, TEST_2)
{
    EXPECT_TRUE(swap_string("ba", "ab"));
}

TEST (TEST_SWAP, TEST_3)
{
    EXPECT_TRUE(swap_string("aaaabc", "aaaacb"));
}

TEST (TEST_SWAP, TEST_4)
{
    EXPECT_TRUE(swap_string("abc", "acb"));
}

TEST (TEST_SWAP, TEST_5)
{
    EXPECT_FALSE(swap_string("abc", "bca"));
}

TEST (TEST_SWAP, TEST_7)
{
    EXPECT_TRUE(swap_string("aa", "aa"));
}
TEST (TEST_SWAP, TEST_8)
{
    EXPECT_TRUE(swap_string("aaa", "aaa"));
}

