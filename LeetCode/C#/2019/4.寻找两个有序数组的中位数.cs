/*
 * @lc app=leetcode.cn id=4 lang=csharp
 *
 * [4] 寻找两个有序数组的中位数
 */
using System;
using System.Collections;
using System.Collections.Generic;
public class FindMedianSortedArraysSolution
// public class Solution
{
    public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    {
        var resList = new List<int>(nums1);
        resList.AddRange(nums2);
        resList.Sort();
        if (resList.Count % 2 == 0)
        {
            return 1.0f * (resList[resList.Count / 2] + resList[resList.Count / 2 - 1]) / 2;
        }
        else
        {
            return 1.0f * resList[(resList.Count - 1) / 2];
        }
    }
    // public double FindMedianSortedArrays(int[] nums1, int[] nums2)
    // { 

    // }
    // public void Test()
    // {
    //     Console.WriteLine("nums1 = [1, 3] , nums2 = [2]:" + FindMedianSortedArrays(new int[] { 1, 3 }, new int[] { 2 }));
    //     Console.WriteLine("nums1 = [1, 2], nums2 = [3, 4]:" + FindMedianSortedArrays(new int[] { 1, 2 }, new int[] { 3, 4 }));
    // }
}

