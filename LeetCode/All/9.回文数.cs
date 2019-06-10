/*
 * @lc app=leetcode.cn id=9 lang=csharp
 *
 * [9] 回文数
 */
using System;
using System.Collections.Generic;

public class IsPalindromeSolution
// public class Solution
{

    public bool IsPalindrome(int x)
    {
        List<int> nums = new List<int>();
        List<int> weis = new List<int>();
        nums.Add(0);
        weis.Add(0);
        if (x < 0)
        {
            return false;
        }
        for (int i = 1; i < int.MaxValue; i++)
        {
            var num = x % (int)Math.Pow(10, i);
            if (nums.Contains(num))
            {
                break;
            }
            nums.Add(num);
            var wei = (num - nums[i - 1]) / (int)Math.Pow(10, i - 1);
            weis.Add(wei);
        }
        int res = 0;
        for (int i = weis.Count - 1; i > 0; i--)
        {
            res += (int)Math.Pow(10, i - 1) * weis[i];
        }
        return res == x;
    }
    public void Test()
    {
        // for (int i = 0; i < 5; i++)
        // {
        //     Console.WriteLine("%:" + 121 % Math.Pow(10, i));
        //     // Console.WriteLine("/:" + 121 / (int)Math.Pow(10, i));
        // }
        Console.WriteLine("121:" + IsPalindrome(121));
        Console.WriteLine("-121:" + IsPalindrome(-121));
        Console.WriteLine("10:" + IsPalindrome(10));
    }

}

