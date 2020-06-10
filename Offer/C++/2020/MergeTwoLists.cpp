#include <iostream>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }

        ListNode *res = new ListNode(0);
        if (l1->val > l2->val)
        {
            res->val = l2->val;
            l2 = l2->next;
        }
        else
        {
            res->val = l1->val;
            l1 = l1->next;
        }
        ListNode *temp = res;
        while (l1 != NULL && l2 != NULL)
        {
            temp->next = l1->val > l2->val ? l2 : l1;
            if (l1->val > l2->val)
            {
                l2 = l2->next;
            }
            else
            {
                l1 = l1->next;
            }
            temp = temp->next;
        }

        while (l1 != NULL)
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2 != NULL)
        {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }

        return res;
    }
};

void Run()
{
    Solution solution;
    ListNode l1(1);
    l1.next = new ListNode(4);
    l1.next->next = new ListNode(7);
    ListNode l2(1);
    l2.next = new ListNode(5);
    l2.next->next = new ListNode(9);
    solution.mergeTwoLists(&l1, &l2);
}