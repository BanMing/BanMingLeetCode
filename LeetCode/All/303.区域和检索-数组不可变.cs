/*
 * @lc app=leetcode.cn id=303 lang=csharp
 *
 * [303] 区域和检索 - 数组不可变
 */
using System.Collections.Generic;
public class NumArray
{
    int[][] f;
    int[] dp;
    public NumArray(int[] nums)
    {
        if (nums.Length < 1)
        {
            return;
        }
        dp = new int[nums.Length];
        dp[0] = nums[0];
        for (int i = 1; i < nums.Length; i++)
        {
            dp[i] = dp[i - 1] + nums[i];
        }

    }

    // 二维数组枚举出所有相加的值
    public void self(int[] nums)
    {
        f = new int[nums.Length][];
        for (int i = 0; i < nums.Length; i++)
        {
            f[i] = new int[nums.Length];
            f[i][i] = nums[i];
            for (int j = i + 1; j < nums.Length; j++)
            {
                f[i][j] = f[i][j - 1] + nums[j];
            }
        }
    }
    public int SumRange(int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        // return f[i][j];
        return dp[j] - (i == 0 ? 0 : dp[i - 1]);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.SumRange(i,j);
 */

