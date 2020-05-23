/******************************************************************
** 文件名: ReversePrint.cpp
** 创建人: BanMing 
** 日  期: 5/23/2020, 10:33:05 PM
** 描  述:  https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

/* 

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：

0 <= 链表长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */
#include <vector>
#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> res;
        while (head)
        {
            res.insert(res.begin(),head->val);
            // res.push_back(head->val);
            // cout << head->val << endl;
            head = head->next;
        }

        return res;
    }
};

void Run()
{
    Solution solution;
    ListNode head(1);
    head.next = new ListNode(3);
    head.next->next = new ListNode(2);
    vector<int> res = solution.reversePrint(&head);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}