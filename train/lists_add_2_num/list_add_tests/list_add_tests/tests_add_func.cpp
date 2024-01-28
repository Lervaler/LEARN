#include "gtest/gtest.h"

#include "../../lists_add_2_num/add_func.h"
#include "../../lists_add_2_num/ListNode.h"

#include "../../lists_add_2_num/recursion_func.h"

#include <vector>

// TEST(One, test_summ_diff_lenght_one)
// {
//  ListNode zero2 = { 1, nullptr };
//  ListNode zero1 = { 1, &zero2 };
//  ListNode one   = { 1, &zero1 };
//  ListNode two   = { 1, &one };
//  ListNode tree  = { 1, &two };
//
//  ListNode one1  = { 1, nullptr };
//  ListNode two1  = { 1, &one1 };
//  ListNode tree1 = { 1, &two1 };
//
//  ListNode *tr = addTwoNumbers(&tree, &tree1);
//
//  std::vector<int> res;
//
//  while (tr)
//  {
//    res.push_back(tr->val);
//    tr = tr->next;
//  }
//  std::vector<int> test = { 2, 2, 2, 1, 1 };
//  EXPECT_EQ(res, test);
// }
//
//
// TEST(Two, test_empty)
// {
//  ListNode tree  = ListNode();
//  ListNode tree1 = ListNode();
//
//  ListNode *tr = addTwoNumbers(&tree, &tree1);
//
//  std::vector<int> res;
//
//  while (tr)
//  {
//    res.push_back(tr->val);
//    tr = tr->next;
//  }
//  std::vector<int> test = { 0 };
//  EXPECT_EQ(res, test);
// }
//
// TEST(Tree, test_same_lenght)
// {
//  ListNode one  = { 4, nullptr };
//  ListNode two  = { 2, &one };
//  ListNode tree = { 2, &two };
//
//  ListNode one1  = { 1, nullptr };
//  ListNode two1  = { 3, &one1 };
//  ListNode tree1 = { 1, &two1 };
//
//
//  ListNode *tr = addTwoNumbers(&tree, &tree1);
//
//  std::vector<int> res;
//
//  while (tr)
//  {
//    res.push_back(tr->val);
//    tr = tr->next;
//  }
//  std::vector<int> test = { 3, 5, 5 };
//  EXPECT_EQ(res, test);
// }
//
// TEST(Four, test_same_lenght2_with_ost)
// {
//  ListNode one  = { 4, nullptr };
//  ListNode two  = { 1, &one };
//  ListNode tree = { 1, &two };
//
//  ListNode one1  = { 1, nullptr };
//  ListNode two1  = { 1, &one1 };
//  ListNode tree1 = { 9, &two1 };
//
//
//  ListNode *tr = addTwoNumbers(&tree, &tree1);
//
//  std::vector<int> res;
//
//  while (tr)
//  {
//    res.push_back(tr->val);
//    tr = tr->next;
//  }
//  std::vector<int> test = { 0, 3, 5 };
//  EXPECT_EQ(res, test);
// }
//
// TEST(Five, test_same_lenght2_with_ost2)
// {
//  ListNode one  = { 9, nullptr };
//  ListNode two  = { 9, &one };
//  ListNode tree = { 9, &two };
//
//  ListNode one1  = { 9, nullptr };
//  ListNode two1  = { 9, &one1 };
//  ListNode tree1 = { 9, &two1 };
//
//
//  ListNode *tr = addTwoNumbers(&tree, &tree1);
//
//  std::vector<int> res;
//
//  while (tr)
//  {
//    res.push_back(tr->val);
//    tr = tr->next;
//  }
//  std::vector<int> test = { 8, 9, 9, 1 };
//  EXPECT_EQ(res, test);
// }
//
// TEST(Six, test_not_same_at_all)
// {
//  ListNode tree = { 0, nullptr };
//
//  ListNode tree7 = { 9, nullptr };
//  ListNode tree6 = { 9, &tree7 };
//  ListNode tree5 = { 9, &tree6 };
//  ListNode tree4 = { 9, &tree5 };
//  ListNode tree3 = { 9, &tree4 };
//  ListNode tree2 = { 9, &tree3 };
//  ListNode tree1 = { 9, &tree2 };
//
//
//  ListNode *tr = addTwoNumbers(&tree, &tree1);
//
//  std::vector<int> res;
//
//  while (tr)
//  {
//    res.push_back(tr->val);
//    tr = tr->next;
//  }
//  std::vector<int> test = { 9, 9, 9, 9, 9, 9, 9 };
//  EXPECT_EQ(res, test);
// }
//
// TEST(Seven, test_not_same_at_all2)
// {
//  ListNode tree = { 1, nullptr };
//
//  ListNode tree7 = { 9, nullptr };
//  ListNode tree6 = { 9, &tree7 };
//  ListNode tree5 = { 9, &tree6 };
//  ListNode tree4 = { 9, &tree5 };
//  ListNode tree3 = { 9, &tree4 };
//  ListNode tree2 = { 9, &tree3 };
//  ListNode tree1 = { 9, &tree2 };
//
//
//  ListNode *tr = addTwoNumbers(&tree, &tree1);
//
//  std::vector<int> res;
//
//  while (tr)
//  {
//    res.push_back(tr->val);
//    tr = tr->next;
//  }
//  std::vector<int> test = { 0, 0, 0, 0, 0, 0, 0, 1 };
//  EXPECT_EQ(res, test);
// }
//
// ////////////////////////////////////////////////////////////////////////////////
// recursion
TEST(Test1, test_summ_diff_lenght_one)
{
  ListNode zero2 = { 1, nullptr };
  ListNode zero1 = { 1, &zero2 };
  ListNode one   = { 1, &zero1 };
  ListNode two   = { 1, &one };
  ListNode tree  = { 1, &two };

  ListNode one1  = { 1, nullptr };
  ListNode two1  = { 1, &one1 };
  ListNode tree1 = { 1, &two1 };

  ListNode *tr = addTwoNumbers_rec(&tree, &tree1);

  std::vector<int> res;

  while (tr)
  {
    res.push_back(tr->val);
    tr = tr->next;
  }
  std::vector<int> test = { 2, 2, 2, 1, 1 };
  EXPECT_EQ(res, test);
}


TEST(Test2, test_empty)
{
  ListNode tree  = ListNode();
  ListNode tree1 = ListNode();

  ListNode *tr = addTwoNumbers_rec(&tree, &tree1);

  std::vector<int> res;

  while (tr)
  {
    res.push_back(tr->val);
    tr = tr->next;
  }
  std::vector<int> test = { 0 };
  EXPECT_EQ(res, test);
}

TEST(Test3, test_same_lenght)
{
  ListNode one  = { 4, nullptr };
  ListNode two  = { 2, &one };
  ListNode tree = { 2, &two };

  ListNode one1  = { 1, nullptr };
  ListNode two1  = { 3, &one1 };
  ListNode tree1 = { 1, &two1 };


  ListNode *tr = addTwoNumbers_rec(&tree, &tree1);

  std::vector<int> res;

  while (tr)
  {
    res.push_back(tr->val);
    tr = tr->next;
  }
  std::vector<int> test = { 3, 5, 5 };
  EXPECT_EQ(res, test);
}

TEST(Test4, test_same_lenght2_with_ost)
{
  ListNode one  = { 4, nullptr };
  ListNode two  = { 1, &one };
  ListNode tree = { 1, &two };

  ListNode one1  = { 1, nullptr };
  ListNode two1  = { 1, &one1 };
  ListNode tree1 = { 9, &two1 };


  ListNode *tr = addTwoNumbers_rec(&tree, &tree1);

  std::vector<int> res;

  while (tr)
  {
    res.push_back(tr->val);
    tr = tr->next;
  }
  std::vector<int> test = { 0, 3, 5 };
  EXPECT_EQ(res, test);
}

TEST(Test5, test_same_lenght2_with_ost2)
{
  ListNode one  = { 9, nullptr };
  ListNode two  = { 9, &one };
  ListNode tree = { 9, &two };

  ListNode one1  = { 9, nullptr };
  ListNode two1  = { 9, &one1 };
  ListNode tree1 = { 9, &two1 };


  ListNode *tr = addTwoNumbers_rec(&tree, &tree1);

  std::vector<int> res;

  while (tr)
  {
    res.push_back(tr->val);
    tr = tr->next;
  }
  std::vector<int> test = { 8, 9, 9, 1 };
  EXPECT_EQ(res, test);
}


TEST(Test6, test_not_same_at_all)
{
  ListNode tree = { 0, nullptr };

  ListNode tree7 = { 9, nullptr };
  ListNode tree6 = { 9, &tree7 };
  ListNode tree5 = { 9, &tree6 };
  ListNode tree4 = { 9, &tree5 };
  ListNode tree3 = { 9, &tree4 };
  ListNode tree2 = { 9, &tree3 };
  ListNode tree1 = { 9, &tree2 };


  ListNode *tr = addTwoNumbers_rec(&tree, &tree1);

  std::vector<int> res;

  while (tr)
  {
    res.push_back(tr->val);
    tr = tr->next;
  }
  std::vector<int> test = { 9, 9, 9, 9, 9, 9, 9 };
  EXPECT_EQ(res, test);
}

TEST(Test7, test_not_same_at_all2)
{
  ListNode tree = { 1, nullptr };

  ListNode tree7 = { 9, nullptr };
  ListNode tree6 = { 9, &tree7 };
  ListNode tree5 = { 9, &tree6 };
  ListNode tree4 = { 9, &tree5 };
  ListNode tree3 = { 9, &tree4 };
  ListNode tree2 = { 9, &tree3 };
  ListNode tree1 = { 9, &tree2 };


  ListNode *tr = addTwoNumbers_rec(&tree, &tree1);

  std::vector<int> res;

  while (tr)
  {
    res.push_back(tr->val);
    tr = tr->next;
  }
  std::vector<int> test = { 0, 0, 0, 0, 0, 0, 0, 1 };
  EXPECT_EQ(res, test);
}
