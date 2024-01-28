#include "recursion_func.h"

ListNode* addTwoNumbers_rec(ListNode *l1,
                            ListNode *l2)
{
  ListNode *ptr = new ListNode();
  int ostatok   = 0;

  ptr->val = (l1->val + l2->val) % 10;

  if ((l1->val + l2->val) >= 10) ostatok = 1;

  if ((l1->next != nullptr) && (l2->next != nullptr) && (ostatok == 0))
  {
    ptr->next = addTwoNumbers_rec(l1->next, l2->next);
  }

  if ((l1->next != nullptr) && (l2->next != nullptr) && (ostatok == 1))
  {
    l1->next->val += ostatok;
    ptr->next      = addTwoNumbers_rec(l1->next, l2->next);
  }

  if ((l1->next == nullptr) && (l2->next != nullptr))
  {
    ListNode ost = { ostatok, nullptr };
    ptr->next = addTwoNumbers_rec(&ost, l2->next);
  }

  if ((l1->next != nullptr) && (l2->next == nullptr))
  {
    ListNode ost = { ostatok, nullptr };
    ptr->next = addTwoNumbers_rec(l1->next, &ost);
  }

  if ((l1->next == nullptr) && (l2->next == nullptr) && (ostatok == 1))
  {
    ptr->next = new ListNode(ostatok);
  }

  return ptr;
}
