/******************************************************************
** 文件名: CuttingRope2.cpp
** 创建人: BanMing 
** 日  期: 6/2/2020, 7:15:45 AM
** 描  述:  面试题14- II. 剪绳子 II
https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

#include <vector>
class Solution
{
public:
    int cuttingRope(int n)
    {
        std::vector<long> dp(n + 1, 0);
        dp[1] = 1;
        for (size_t i = 2; i < n + 1; i++)
        {
            for (size_t j = 1; j <= i; j++)
            {
                long m = std::max(((i - j) * j)%1000000007, (dp[i - j] * j)%1000000007);
                dp[i] = std::max(dp[i], m);
            }
        }
        return dp[n];
    }
};

void Run()
{
    Solution solution;
    // printf("n = 8 x = %d \n", solution.cuttingRope(8));
    // printf("n = 10 x = %d \n", solution.cuttingRope(10));
    printf("n = 120 x = %d \n", solution.cuttingRope(120));
}