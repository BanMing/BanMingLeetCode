/*
 * @lc app=leetcode.cn id=11 lang=csharp
 *
 * [11] 盛最多水的容器
 */
public class MaxAreaSolution
// public class Solution
{
    public int MaxArea(int[] height)
    {
        int max = 0;
        int i = 0;
        int j = height.Length - 1;
        // for (int i = height.Length - 1; i >= 0; i--)
        // {
        //     // for (int j = 0; j < height.Length; j++)
        //     // {
        //     //     // System.Math.Min(height[i],height[j])*(i-j)
        //     //     max = System.Math.Max(max, System.Math.Min(height[i], height[j]) * (i - j));
        //     // }
        // }
        while (j > i)
        {
            var h = System.Math.Min(height[i], height[j]);
            max = System.Math.Max(max, h * (j - i));
            // 向后寻找大于现在的高度
            while (j > i && h >= height[i])
            {
                i++;
            }
            while (j > i && h >= height[j])
            {
                j--;
            }
        }
        return max;
    }
    public void Test()
    {
        System.Console.WriteLine("1,8,6,2,5,4,8,3,7:" + MaxArea(new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 }));
    }
}

