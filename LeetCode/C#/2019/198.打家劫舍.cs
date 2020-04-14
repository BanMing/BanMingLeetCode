/*
 * @lc app=leetcode.cn id=198 lang=csharp
 *
 * [198] 打家劫舍
 */
public class RobSolution
// public class Solution
{
    // 动态规划
    public int Rob(int[] nums)
    {
        if (nums.Length < 1)
        {
            return 0;
        }
        if (nums.Length < 2)
        {
            return nums[0];
        }
        var f = new int[nums.Length];
        f[0] = nums[0];
        f[1] = System.Math.Max(nums[0], nums[1]);
        for (int i = 2; i < nums.Length; i++)
        {
            // 计算出相隔1位之前加上现在这个数最大的值
            // for (int j = 2; j <= i; j++)
            // {
            //     f[i] = System.Math.Max(f[i - j] + nums[i], f[i]);
            // }
            f[i] = System.Math.Max(f[i - 1], f[i - 2] + nums[i]);
            System.Console.WriteLine($"f[{i}]={f[i]}");
        }
        return f[nums.Length-1];
    }

    public void Test()
    {
        // System.Console.WriteLine("1,2,3,1:" + Rob(new int[] { 1, 2, 3, 1 }));
        // System.Console.WriteLine("2,7,9,3,1:" + Rob(new int[] { 2, 7, 9, 3, 1 }));
        System.Console.WriteLine("1,3,1,3,100:" + Rob(new int[] { 1, 3, 1, 3, 100 }));
    }
}

