/*
 * @lc app=leetcode.cn id=70 lang=csharp
 *
 * [70] 爬楼梯
 */
using System;
using System.Collections.Generic;
// public class Solution
public class ClimbStairsSolution
{
    public int ClimbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        var f = new int[n + 1];
        f[0] = 0;
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            // 动态规划公式
            // 第i阶所有次数是i-1与i-2阶的总和
            f[i] = f[i - 1] + f[i - 2];
            // System.Console.WriteLine($"f[{i}]={f[i]}");
        }
        return f[n];
    }
    public void Test()
    {
        Console.WriteLine("1:" + ClimbStairs(1));
        // Console.WriteLine("2:" + ClimbStairs(2));
        // Console.WriteLine("3:" + ClimbStairs(3));
        // Console.WriteLine("4:" + ClimbStairs(4));
    }
}

