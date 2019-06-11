/*
 * @lc app=leetcode.cn id=53 lang=csharp
 *
 * [53] 最大子序和
 */
// public class Solution
public class MaxSubArraySolution
{
    public int MaxSubArray(int[] nums)
    {
        if (nums.Length < 1)
        {
            return 0;
        }
        int[] f = new int[nums.Length];
        f[0] = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.Length; i++)
        {
            f[i] = System.Math.Max(f[i - 1] + nums[i], nums[i]);
            max = System.Math.Max(f[i], max);
            System.Console.WriteLine($"f[{i}]={f[i]}");
        }
        return max;
    }
    public void Test()
    {
        // System.Console.WriteLine("-2,1,-3,4,-1,2,1,-5,4:" + MaxSubArray(new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
        System.Console.WriteLine("-2,1,-3:" + MaxSubArray(new int[] { -2, 1, -3 }));
        // System.Console.WriteLine("1,1,-2:" + MaxSubArray(new int[] { 1, 1, -2 }));
        // System.Console.WriteLine("-2,-1:" + MaxSubArray(new int[] { -2, -1 }));
        // System.Console.WriteLine("8,-19,5,-4,20:" + MaxSubArray(new int[] { 8, -19, 5, -4, 20 }));
    }
}

