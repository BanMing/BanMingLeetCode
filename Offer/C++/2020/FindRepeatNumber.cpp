/******************************************************************
** 文件名: FindRepeatNumber.cpp
** 创建人: BanMing 
** 日  期: 5/15/2020, 8:52:15 AM
** 描  述:  https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
/*
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 

限制：

2 <= n <= 100000
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        map<int, int> numMap;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (numMap[nums[i]] == 0)
            {
                numMap[nums[i]] = 1;
            }
            else
            {
                return nums[i];
            }
        }
        return 0;
    }
};

void Run()
{
    Solution solution;
    int test[] = {11, 23, 4, 44};
    vector<int> test1(test, test + 4);
    // for (auto &&i : test1)
    // {
    //     cout << i << endl;
    // }

    cout << solution.findRepeatNumber(test1) << endl;
}