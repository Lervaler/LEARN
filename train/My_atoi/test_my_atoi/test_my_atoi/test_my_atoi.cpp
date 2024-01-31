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
  int test      = -INT_MAX - 1;
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
