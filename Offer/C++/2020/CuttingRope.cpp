/******************************************************************
** 文件名: CuttingRope.cpp
** 创建人: BanMing 
** 日  期: 5/31/2020, 11:10:47 PM
** 描  述:  面试题14- I. 剪绳子
https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <vector>
class Solution
{
public:
    int cuttingRopeSelf(int n)
    {
        if (n == 2)
        {
            return 1;
        }

        if (n <= 4)
        {
            return n;
        }
        int dp[n + 1];
        for (int i = 0; i <= 4; i++)
        {
            dp[i] = i;
        }
        dp[5] = 6;
        dp[6] = 9;
        for (int i = 7; i <= n; i++)
        {
            dp[i] = 3 * dp[i - 3];
        }
        return dp[n];
    }

    int cuttingRope(int n)
    {
        if (n<=3)
        {
           return n-1;
        }
        
        std::vector<int> dp(n + 1, 0);
        // int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                // int m = dp[j - i] * i;
                // dp[j] = std::max(dp[j], m);
                if (i - j >= 0)
                {
                    int m = dp[i - j] * j;
                    int mm = (i - j) * j;
                    int max = std::max(m, mm);
                    dp[i] = std::max(dp[i], max);
                }
                else
                {
                    break;
                }
            }
        }
        return dp[n];
    }
};

void Run()
{
    Solution solution;
    printf("n = 8 x = %d \n", solution.cuttingRope(8));
    printf("n = 10 x = %d \n", solution.cuttingRope(10));
}