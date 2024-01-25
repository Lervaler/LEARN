#include <iostream>

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

struct ListNode {
  int       val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *l3  = new ListNode();
  ListNode *ptr = l3;
  int ostatok   = 0;
  int celoe     = 0;

  while (l3)
  {
    celoe   = l1->val + l2->val + ostatok;
    ostatok = 0;

    if (celoe >= 10) ostatok = 1;

    ptr->val = celoe % 10;

    if ((l1->next != nullptr) ||
        (l2->next != nullptr))
    {
      ptr->next = new ListNode(0, nullptr);
      ptr       = ptr->next;
    }

    if ((l1->next == nullptr) && (l2->next == nullptr) && (ostatok == 1))
    {
      ptr->next = new ListNode(1, nullptr);
    }

    if ((l1->next == nullptr) && (l2->next == nullptr)) break;

    if (l1->next == nullptr) l1->val = 0;
    else l1 = l1->next;

    if (l2->next == nullptr) l2->val = 0;
    else l2 = l2->next;
  }

  ptr = l3;
  return ptr;
}

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
