/*
 * @lc app=leetcode.cn id=62 lang=csharp
 *
 * [62] 不同路径
 */
// public class Solution
public class UniquePathsSolution
{
    public int UniquePaths(int m, int n)
    {
        var dp = new int[m + 1][];
        for (int i = 0; i <= m; i++)
        {
            dp[i] = new int[n + 1];
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == 1 || i == 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    // dp[i][j] = dp[i][j - 1] + i - 1;
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];// System.Math.Max(dp[i - 1][j] + 1, dp[i][j] + 1);
                }

            }
        }
        return dp[m][n];
    }
    public void Test()
    {
        System.Console.WriteLine("2,3:" + UniquePaths(2, 3));
        System.Console.WriteLine("7,3:" + UniquePaths(7, 3));
    }
}

