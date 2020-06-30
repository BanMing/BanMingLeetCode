/******************************************************************
** 文件名: ValidateStackSequences.cpp
** 创建人: BanMing 
** 日  期: 6/30/2020, 10:42:46 PM
** 描  述:  剑指 Offer 31. 栈的压入、弹出序列
https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        if (pushed.empty() && popped.empty())
        {
            return true;
        }

        if (pushed.empty() || popped.empty() || pushed.size() != popped.size())
        {
            return false;
        }

        int i = 0;
        int j = 0;
        stack<int> temp;
        while (i < pushed.size())
        {
            while (i < pushed.size() && pushed[i] != popped[j])
            {
                temp.push(pushed[i]);
                i++;
            }
            if (i < pushed.size() && pushed[i] == popped[j])
            {
                j++;
                i++;
            }
            while (!temp.empty() && temp.top() == popped[j])
            {
                j++;
                temp.pop();
            }
        }
        while (!temp.empty() && temp.top() == popped[j])
        {
            j++;
            temp.pop();
        }
        return j == popped.size();
    }
};

void Run()
{
    int pushA[] = {8, 9, 2, 3, 7, 0, 5, 4, 6, 1};
    int popA[] = {6, 8, 2, 1, 3, 9, 0, 7, 4, 5};
    vector<int> push(pushA, pushA + 10); // = {1, 2, 3, 4, 5};
    vector<int> pop(popA, popA + 10);    // = {4, 5, 3, 2, 1};
    Solution solution;
    printf("%d \n", solution.validateStackSequences(push, pop));
}