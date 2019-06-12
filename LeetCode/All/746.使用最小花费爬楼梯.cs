/*
 * @lc app=leetcode.cn id=746 lang=csharp
 *
 * [746] 使用最小花费爬楼梯
 */
public class MinCostClimbingStairsSolution
// public class Solution
{
    public int MinCostClimbingStairs(int[] cost)
    {
        int[] dp = new int[cost.Length];

        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.Length; i++)
        {

            dp[i] = System.Math.Min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
            // System.Console.WriteLine($"dp[{i}]={dp[i]}");
        }
        return System.Math.Min(dp[cost.Length - 1], dp[cost.Length - 2]);
    }
    public void Test()
    {
        System.Console.WriteLine("10, 15, 20,1:" + MinCostClimbingStairs(new int[] { 10, 15, 20 }));
        // System.Console.WriteLine("1, 100, 1, 1, 1, 100, 1, 1, 100, 1:" + MinCostClimbingStairs(new int[] { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 }));
    }
}

