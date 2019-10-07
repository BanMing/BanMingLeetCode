/*
 * @lc app=leetcode.cn id=8 lang=csharp
 *
 * [8] 字符串转换整数 (atoi)
 */
using System;
using System.Text;
using System.Collections;
using System.Collections.Generic;
public class MyAtoiSolution
// public class Solution
{
    public int MyAtoi(string str)
    {
        str = str.TrimStart();
        if (string.IsNullOrEmpty(str))
        {
            return 0;
        }
        int fu = 1;
        int index = 0;
        if (str[0] == '-')
        {
            fu = -1;
            index = 1;
        }
        if (str[0] == '+')
        {
            index = 1;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = index; i < str.Length; i++)
        {
            if (!isNum(str[i].ToString()))
            {
                break;
            }
            else
            {
                sb.Append(str[i]);
            }
        }
        // 这种方式2147483646通不过
        // var max = (int)Math.Pow(10, sb.Length) * int.Parse(sb[0].ToString());
        // if (sb.Length > 0 && max > int.MaxValue)
        // {
        //     return fu == 1 ? int.MaxValue : int.MinValue;
        // }
        int res = 0;
        int.TryParse(sb.ToString(), out res);
        // 判断是否越界
        if (res == 0 && sb.Length > 0 && int.Parse(sb[0].ToString()) > 0)
        {
            return fu == 1 ? int.MaxValue : int.MinValue;
        }
        return res * fu;
    }

    private bool isNum(string str)
    {
        //ASCII码判断是否是数字 0->46,9->57
        var bytes = System.Text.Encoding.ASCII.GetBytes(str);
        var asc = (short)bytes[0];
        return asc > 47 && asc < 58;
    }
    public void Test()
    {
        // Console.WriteLine("sss:" + "s   -42".Replace(" ",""));
        // Console.WriteLine("42:" + MyAtoi("42"));
        // Console.WriteLine("   -42:" + MyAtoi("   -42"));
        // Console.WriteLine("4193 with words:" + MyAtoi("4193 with words"));
        // Console.WriteLine("words and 987:" + MyAtoi("words and 987"));
        Console.WriteLine("-91283472332:" + MyAtoi("-91283472332"));
        // Console.WriteLine("   +0 123:" + MyAtoi("   +0 123"));
        Console.WriteLine("2147483646:" + MyAtoi("2147483646"));
    }
}

