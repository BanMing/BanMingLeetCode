/******************************************************************
** 文件名: MinStack.cpp
** 创建人: BanMing 
** 日  期: 6/30/2020, 7:05:10 AM
** 描  述:  剑指 Offer 30. 包含min函数的栈
https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class MinStack
{
private:
    stack<int> data;
    stack<int> minData;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        data.push(x);
        if (minData.empty() || minData.top() >= x)
        {
            minData.push(x);
        }
    }

    void pop()
    {
        if (!data.empty())
        {
            if (data.top() == minData.top())
                minData.pop();
            data.pop();
        }
    }

    int top()
    {
        return data.top();
    }

    int min()
    {
        return minData.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */