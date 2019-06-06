/*
 * @lc app=leetcode.cn id=6 lang=csharp
 *
 * [6] Z 字形变换
 */
// public class Solution {
using System.Text;
using System.Collections.Generic;
using System;

// public class ConvertSolution
public class Solution
{
    public string Convert(string s, int numRows)
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

    public string ConvertNet(string s, int numRows)
    {
        var strs = new string[numRows];
        for (int i = 0; i < numRows; i++)
        {
            strs[i] = "";
        }
        for (int i = 0; i < s.Length;)
        {
            for (int j = 0; j < numRows; j++)
            {
                strs[j] += s[i];
                i++;
            }
            for (int j = 0; j < length; j++)
            {
                
            }
        }
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

