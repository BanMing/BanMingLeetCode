/******************************************************************
** 文件名: Fib.cpp
** 创建人: BanMing 
** 日  期: 5/26/2020, 11:23:24 PM
** 描  述:  https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

class Solution
{
public:
    int fibcrusion(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        return fibcrusion(n - 1) % 1000000007 + fibcrusion(n - 2) % 1000000007;
    }

    int fib(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }

    int fibBest(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int pre = 0;
        int next = 1;
        for (int i = 2 i <= n; i++)
        {
            int temp = next;
            next = (next + pre)% 1000000007;
            pre = temp;
        }
        return next;
    }
};