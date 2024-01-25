#include <iostream>
#include <add_func.h>
#include <ListNode.h>

/*
   You are given two non-empty linked lists representing two non-negative
      integers.
   The digits are stored in reverse order, and each of their nodes contains a
      single digit.
   Add the two numbers and return the sum as a linked list.
   You may assume the two numbers do not contain any leading zero, except the
      number 0 itself.

   The number of nodes in each linked list is in the range [1, 100].
   0 <= Node.val <= 9
   It is guaranteed that the list represents a number that does not have leading
      zeros.
 */

// Definition for singly-linked list.


int main()
{
  ListNode zero2 = { 9, nullptr };
  ListNode zero1 = { 9, &zero2 };
  ListNode one   = { 9, &zero1 };
  ListNode two   = { 9, &one };
  ListNode tree  = { 9, &two };

  ListNode one1  = { 9, nullptr };
  ListNode two1  = { 9, &one1 };
  ListNode tree1 = { 9, &two1 };

  ListNode *tr = addTwoNumbers(&tree, &tree1);


  while (tr)
  {
    std::cout << tr->val << " ";
    tr = tr->next;
  }

  return 0;
}
