/******************************************************************
** 文件名: DeleteNode.cpp
** 创建人: BanMing 
** 日  期: 6/4/2020, 7:20:51 AM
** 描  述:  面试题18. 删除链表的节点

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
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
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *res = head;
        if (head->val == val)
        {
            return res->next;
        }

        while (head)
        {
            ListNode *next = head->next;
            if (next->val == val)
            {
                ListNode *nextNext = next->next;
                head->next = nextNext;
                break;
            }
            head = head->next;
        }
        return res;
    }
};

void Run()
{
}