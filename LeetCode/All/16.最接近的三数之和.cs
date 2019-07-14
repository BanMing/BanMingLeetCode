/*
 * @lc app=leetcode.cn id=16 lang=csharp
 *
 * [16] 最接近的三数之和
 */
using System;
using System.Collections;
using System.Collections.Generic;
// public class ThreeSumClosestSolution
public class Solution
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        var numList = new List<int>(nums);
        numList.Sort();
        int minIndex = int.MaxValue;
        int min = int.MaxValue;
        for (int i = 0; i < numList.Count; i++)
        {
            if (min > numList[i] - target)
            {
                min = numList[i] - target;
                minIndex = i;
            }
        }
        var res = new List<int>();
        if (minIndex + 1 < numList.Count && minIndex - 1 > 0)
        {
            res.Add(numList[minIndex + 1] + numList[minIndex] + numList[minIndex - 1]);
        }
        if (minIndex + 1 < numList.Count - 1)
        {
            res.Add(numList[minIndex + 1] + numList[minIndex] + numList[minIndex + 2]);
        }
        if (minIndex - 2 > 0)
        {
            res.Add(numList[minIndex - 1] + numList[minIndex] + numList[minIndex - 2]);
        }
        int minRes = int.MaxValue;
        for (int i = 0; i < res.Count; i++)
        {
            minRes = (res[i] - 3 * target) > minRes ? minRes : res[i] - 3 * target;
        }
        return minRes;
    }
    public void Test()
    {

    }
}

