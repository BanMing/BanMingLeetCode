/*
 * @lc app=leetcode.cn id=7 lang=csharp
 *
 * [7] 整数反转
 */
using System;
using System.Collections;
using System.Collections.Generic;
public class ReverseSolution
// public class Solution
{
    public int Reverse(int x)
    {
        if (x >= int.MaxValue)
        {
            return 0;
        }
        if (x <= int.MinValue)
        {
            return 0;
        }
        int fu = x > 0 ? 1 : -1;
        x = Math.Abs(x);
        var list = new List<char>();
        list.AddRange(x.ToString().ToCharArray());
        list.Reverse();
        var resStr = string.Concat(list);
        // Console.WriteLine(resStr);
        int res = 0;
        int.TryParse(resStr, out res);
        return res * fu;
    }
    public void Test()
    {
        Console.WriteLine("123:" + Reverse(123));
        Console.WriteLine("-123:" + Reverse(-123));
        Console.WriteLine("120:" + Reverse(120));
    }
}

