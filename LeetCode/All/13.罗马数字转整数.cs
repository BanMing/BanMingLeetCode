/*
 * @lc app=leetcode.cn id=13 lang=csharp
 *
 * [13] 罗马数字转整数
 */
using System.Collections.Generic;
public class RomanToIntSolution
// public class Solution
{
    public int RomanToIntSelf(string s)
    {
        int res = 0;
        string[] specilStrs = new string[] { "CM", "CD", "XC", "XL", "IX", "IV" };
        int[] nums = new int[] { 900, 400, 90, 40, 9, 4 };
        for (int i = 0; i < specilStrs.Length; i++)
        {
            if (s.Contains(specilStrs[i]))
            {
                s = s.Replace(specilStrs[i], "");
                res += nums[i];
            }
        }

        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == 'M')
            {
                res += 1000;
            }
            else if (s[i] == 'D')
            {
                res += 500;
            }
            else if (s[i] == 'C')
            {
                res += 100;
            }
            else if (s[i] == 'L')
            {
                res += 50;
            }
            else if (s[i] == 'X')
            {
                res += 10;
            }
            else if (s[i] == 'V')
            {
                res += 5;
            }
            else if (s[i] == 'I')
            {
                res += 1;
            }
        }
        return res;
    }
    public int RomanToInt(string s)
    {
        Dictionary<char, int> map = new Dictionary<char, int>() { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        int res = map[s[s.Length - 1]];
        for (int i = s.Length - 2; i >= 0; i--)
        {
            res += map[s[i]] < map[s[i + 1]] ? -map[s[i]] : map[s[i]];
        }
        return res;
    }
    public void Test()
    {
        System.Console.WriteLine("III:" + RomanToInt("III"));
        System.Console.WriteLine("IV:" + RomanToInt("IV"));
        System.Console.WriteLine("IX:" + RomanToInt("IX"));
        System.Console.WriteLine("LVIII:" + RomanToInt("LVIII"));
        System.Console.WriteLine("MCMXCIV:" + RomanToInt("MCMXCIV"));
        System.Console.WriteLine("MCDLXXVI:" + RomanToInt("MCDLXXVI"));
        System.Console.WriteLine("MCDLXXVI:" + RomanToInt("MCDLXXVI"));
    }
}

