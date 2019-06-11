//////////////////////////////////////////////////////////////////////////////////////////
//// DPTest.cs
//// time:2019/6/11 下午4:01:48			
//// author:BanMing   
//// des:动态规划测试
// https://www.zhihu.com/question/23995189
////////////////////////////////////////////////////////////////////////////////////////////

using System;
using System.Collections;
using System.Collections.Generic;

public class DPTest
{

    // 分割钱币
    // f(n)= min{f(n-1),f(n-5),f(n-11)} + 1
    public int SplitMoney(int allMoney)
    {
        int[] f = new int[allMoney + 1];
        f[0] = 0;
        for (int i = 1; i <= allMoney; i++)
        {
            int minCost = int.MaxValue;
            if (i >= 1)
            {
                minCost = System.Math.Min(minCost, f[i - 1] + 1);
            }
            if (i >= 5)
            {
                minCost = System.Math.Min(minCost, f[i - 5] + 1);
            }
            if (i >= 11)
            {
                minCost = System.Math.Min(minCost, f[i - 11] + 1);
            }
            f[i] = minCost;
            Console.WriteLine($"f[{i}]={f[i]}");
        }
        int res = System.Math.Min(f[allMoney - 1], f[allMoney - 5]);
        return System.Math.Min(f[allMoney - 11], res) + 1;
    }

    // 最长上升子序列
    // 
    public int LIS(int[] a, int n)
    {
        var f = new int[n + 1];
        f[0] = 1;
        for (int x = 0; x < n; x++)
        {
            //  考虑比x小的每一个p：如果 a_x>a_p ，那么f(x)可以取f(p)+1.
            // 　解释：我们把 a_x 接在 a_p 的后面，肯定能构造一个以 a_x 结尾的上升子序列，长度比以 a_p 结尾的LIS大1.那么，我们可以写出状态转移方程了：
            for (int p = 0; p < x; p++)
            {
                if (a[p] < a[x]) { f[x] = System.Math.Max(f[x], f[p] + 1); }
            }
            Console.WriteLine($"f[{x}]={f[x]}");
        }
        int res = int.MinValue;
        for (int i = 0; i < n; i++)
        {
            res = Math.Max(res, f[i]);
        }
        return res;
    }

    public void Test()
    {
        // Console.WriteLine("Split Money 15:" + SplitMoney(15));
        Console.WriteLine(LIS(new int[] { 1, 5, 3, 4, 6, 9, 7, 8 }, 8));
    }
}