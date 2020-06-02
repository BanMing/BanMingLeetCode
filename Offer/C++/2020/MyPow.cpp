/******************************************************************
** 文件名: MyPow.cpp
** 创建人: BanMing 
** 日  期: 6/3/2020, 7:13:19 AM
** 描  述:  面试题16. 数值的整数次方
https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
class Solution
{
public:
    double myPow(double x, int n)
    {
        int len = n < 0 ? -n : n;
        double res = 1;
        for (int i = 1; i <= len; i++)
        {
            res *= x;
        }
        res = n < 0 ? 1 / res : res;
        return res;
    }
};

void Run()
{
    Solution solution;
    printf("x = 2.000 n = 10 res = %f \n", solution.myPow(2.00000, 10));
    printf("x = 2.100 n = 3 res = %f \n", solution.myPow(2.10000, 3));
    printf("x = 2.000 n = -2 res = %f \n", solution.myPow(2.00000, -2));
}