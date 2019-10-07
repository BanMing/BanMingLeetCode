/*
 * @lc app=leetcode.cn id=6 lang=csharp
 *
 * [6] Z 字形变换
 */
// public class Solution {
using System.Text;
using System.Collections.Generic;
using System;

public class ConvertSolution
// public class Solution
{
    // 寻找规律，推到公式，不是很好的办法
    public string ConvertSelf(string s, int numRows)
    {
        if (s.Length == 1 || numRows == 1)
        {
            return s;
        }
        StringBuilder res = new StringBuilder();
        int num = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++)
        {
            int index = 0;
            while (index * num + i < s.Length)
            {
                res.Append(s[index * num + i]);
                // 这个公式没发现
                if (i != 0 && i != numRows - 1 && index * num - i + num < s.Length)
                {
                    res.Append(s[index * num - i + num]);
                }
                index++;
            }

        }
        return res.ToString();
    }

    // 以每一行排列来依次累加
    // 从第一列开计算
    // 更加取巧
    public string Convert(string s, int numRows)
    {
        var strs = new string[numRows];
        // 存储每行基础数据
        for (int i = 0; i < numRows; i++)
        {
            strs[i] = "";
        }
        for (int i = 0; i < s.Length;)
        {
            // 计算全部都是齐的一列
            for (int j = 0; j < numRows && i < s.Length; j++)
            {
                strs[j] += s[i];
                i++;
            }
            // 计算z字斜像
            for (int j = numRows - 2; j > 0 && i < s.Length; j--)
            {
                strs[j] += s[i];
                i++;
            }
        }
        string res = "";
        for (int i = 0; i < numRows; i++)
        {
            res += strs[i];
        }
        return res;
    }
    public void Test()
    {
        // LCIREOSIEDHN
        // LCIRETSIEDHN
        // LCIRE3O7S11IEDHN
        // LCIRETOESIIGEDHN
        Console.WriteLine("LEETCODEISHIRING:" + Convert("LEETCODEISHIRING", 3));
        // LDRECEHIEOIINTSG
        // LDREOEIIECIHNTSG
        Console.WriteLine("LEETCODEISHIRING:" + Convert("LEETCODEISHIRING", 4));
        // PINALSIGYAHPI
        // PINALSIGYAHRPI
        Console.WriteLine("PAYPALISHIRING:" + Convert("PAYPALISHIRING", 4));
        Console.WriteLine("AB:" + Convert("AB", 1));
    }
}

