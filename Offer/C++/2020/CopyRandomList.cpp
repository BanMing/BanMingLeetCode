/******************************************************************
** 文件名: CopyRandomList.cpp
** 创建人: BanMing 
** 日  期: 7/13/2020, 10:16:27 PM
** 描  述:  剑指 Offer 35. 复杂链表的复制
https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *node = head;

        map<Node *, Node *> map;
        while (node != NULL)
        {
            map[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while (node != NULL)
        {
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
            node = node->next;
        }
        return map[head];
    }
    Node *copyRandomListSelf(Node *head)
    {
        if (head == NULL || (head->next == NULL && head->random == NULL))
        {
            return head;
        }
        Node *test = head;
        Node *temp;
        Node *res;
        res = temp;
        // res->next = temp;
        while (head != NULL)
        {
            temp->val = (head->val);
            if (head->next != NULL)
            {
                temp->next = new Node(head->next->val);
            }
            if (head->random != NULL)
            {
                temp->random = new Node(head->random->val);
            }
            temp = temp->next;
            head = head->next;
        }
        return res;
    }
};
void Run()
{
    //  [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node *test = new Node(7);
    test->random = NULL;

    test->next = new Node(13);
    test->next->random = new Node(0);

    test->next->next = new Node(11);
    test->next->next->random = new Node(4);

    test->next->next->next = new Node(10);
    test->next->next->next->random = new Node(2);

    test->next->next->next->next = new Node(1);
    test->next->next->next->next->random = new Node(7);

    Solution solution;
    solution.copyRandomList(test);
}
