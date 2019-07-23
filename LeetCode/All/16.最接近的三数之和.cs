/*
 * @lc app=leetcode.cn id=16 lang=csharp
 *
 * [16] 最接近的三数之和
 */
using System;
using System.Collections;
using System.Collections.Generic;
public class ThreeSumClosestSolution
// public class Solution
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        int res = 0;

        if (nums.Length < 4)
        {
            for (int i = 0; i < nums.Length; i++)
            {
                res += nums[i];
            }
        }

        var disList = new List<int>(nums);
        disList.Add(target);

        disList.Sort();

        int index = disList.IndexOf(target);
        if (index + 3 < disList.Count)
        {
            res = disList[index + 1] + disList[index + 2] + disList[index + 3];
            // minDis = 3 * target - minDis;
        }
        if (index - 3 >= 0)
        {
            res = Math.Max(res, disList[index - 1] + disList[index - 2] + disList[index - 3]);
        }
        if (index - 1 >= 0 && index + 2 < disList.Count)
        {
            res = Math.Max(res, disList[index - 1] + disList[index + 1] + disList[index + 2]);
        }
        if (index - 2 >= 0 && index + 1 < disList.Count)
        {
            res = Math.Max(res, disList[index - 1] + disList[index - 2] + disList[index + 1]);
        }


        return res;
    }
    public void Test()
    {
        System.Console.WriteLine("nums = [-1，2，1，-4] target = 1:" + ThreeSumClosest(new int[] { -1, 2, 1, -4 }, 1));
        // System.Console.WriteLine("nums = [0, 0, 0] target = 1:" + ThreeSumClosest(new int[] { 0, 0, 0 }, 1));
        // System.Console.WriteLine("nums = [1, 1, 1,1] target = 0:" + ThreeSumClosest(new int[] { 1, 1, 1, 1 }, 0));
        // System.Console.WriteLine("nums = [1, 1, 1,0] target = -100:" + ThreeSumClosest(new int[] { 1, 1, 1, 0 }, -100));
    }
}

