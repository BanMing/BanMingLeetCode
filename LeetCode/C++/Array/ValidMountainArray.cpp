/******************************************************************
** ValidMountainArray.cpp
** @Author       : BanMing 
** @Date         : 2020/8/25 上午10:53:15
** @Description  : https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/
*******************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        if (A.size() < 3)
        {
            return false;
        }
        bool isRaise = true;
        for (size_t i = 1; i < A.size(); i++)
        {
            if (isRaise && A[i] <= A[i - 1])
            {
                isRaise = false;
            }

            if (A[i] >= A[i - 1] && !isRaise)
            {
                return false;
            }
        }
        return true;
    }
};

void Run() {}