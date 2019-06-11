/*
 * @lc app=leetcode.cn id=53 lang=csharp
 *
 * [53] 最大子序和
 */
public class Solution
// public class MaxSubArraySolution
{
    public int MaxSubArray(int[] nums)
    {
        if (nums.Length < 1)
        {
            return 0;
        }
        int[] f = new int[nums.Length];
        f[0] = nums[0];
        int max = int.MinValue;
        for (int i = 1; i < nums.Length; i++)
        {
            if (f[i - 1] < f[i - 1] + nums[i])
            {
                if (nums[i] > f[i - 1])
                {
                    f[i] = nums[i];
                }
                else
                {
                    if (f[i - 1] == f[i - 2])
                    {

                        f[i] = f[i - 1] + nums[i] + nums[i - 1];
                    }
                    else
                    {
                        f[i] = f[i - 1] + nums[i];
                    }
                }
            }
            else
            {
                f[i] = f[i - 1];
            }
            max = System.Math.Max(max, f[i]);
            // System.Console.WriteLine($"f[{i}]={f[i]}");
        }
        return max;
    }
    public void Test()
    {
        System.Console.WriteLine("-2,1,-3,4,-1,2,1,-5,4:" + MaxSubArray(new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 }));
    }
}

