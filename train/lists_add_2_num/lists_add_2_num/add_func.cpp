#include <add_func.h>

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
