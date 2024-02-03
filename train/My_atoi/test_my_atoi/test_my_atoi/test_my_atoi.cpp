#include "../../My_atoi/my_atoi.cpp"

#include <gtest/gtest.h>

TEST(Test1, test1)
{
  std::string s = "42";
  int test      = 42;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}
TEST(Test1_1, test1_1)
{
  std::string s = "-42";
  int test      = -42;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}


TEST(Test2, test2)
{
  std::string s = " 42";
  int test      = 42;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test3, test3)
{
  std::string s = "     42";
  int test      = 42;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test4, test4)
{
  std::string s = "a42";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test5, test5)
{
  std::string s = "0";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test6, test6)
{
  std::string s = "aaa";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test7, test7)
{
  std::string s = "91283472332";
  int test      = INT_MAX;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test8, test8)
{
  std::string s = "-91283472332";
  int test      = -2147483648;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}


TEST(Test9, test9)
{
  std::string s = "+1";
  int test      = 1;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}
TEST(Test10, test10)
{
  std::string s = "+-12";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}
TEST(Test11, test11)
{
  std::string s = "-+12";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test12, test12)
{
  std::string s = "00000-42a1234";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test13, test13)
{
  std::string s = "00034";
  int test      = 34;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test14, test14)
{
  std::string s = "-000000000000000000000000000000000000000000000000001";
  int test      = -1;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test15, test15)
{
  std::string s = "-2147483647";
  int test      = -2147483647;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test16, test16)
{
  std::string s = "-2147483648";
  int test      = -2147483648;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test17, test17)
{
  std::string s = "2147483648";
  int test      = 2147483647;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}
TEST(Test18, test18)
{
  std::string s = "-91283472332";
  int test      = -2147483648;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test19, test19)
{
  std::string s = "102";
  int test      = 102;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test20, test20)
{
  std::string s = "3.14159";
  int test      = 3;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test21, test21)
{
  std::string s = "  0000000000012345678";
  int test      = 12345678;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test22, test22)
{
  std::string s = "  -0012a42";
  int test      = -12;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test23, test23)
{
  std::string s = "   +0 123";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test24, test24)
{
  std::string s = "-13+8";
  int test      = -13;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test25, test25)
{
  std::string s = "  +  413";
  int test      = 0;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}

TEST(Test26, test26)
{
  std::string s = "        +1114054094z0";
  int test      = 1114054094;
  int res       = myAtoi(s);

  EXPECT_EQ(test, res);
}
