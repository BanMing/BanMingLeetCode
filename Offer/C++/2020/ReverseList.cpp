#include <iostream>
#include <stack>
using namespace std;
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        stack<ListNode *> listNodeStack;
        while (head)
        {
            listNodeStack.push(head);
            head = head->next;
        }
        head = listNodeStack.top();
        listNodeStack.pop();
        ListNode *res = head;
        while (!listNodeStack.empty())
        {
            head->next = listNodeStack.top();
            head = head->next;
            listNodeStack.pop();
        }
        head->next = NULL;
        return res;
    }
};

void Run()
{
    ListNode *head = new ListNode(1);
    ListNode *test = head;
    for (int i = 2; i <= 5; i++)
    {
        head->next = new ListNode(i);
        head = head->next;
    }
    Solution solution;
    solution.reverseList(test);
}