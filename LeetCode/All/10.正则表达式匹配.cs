/*
 * @lc app=leetcode.cn id=10 lang=csharp
 *
 * [10] 正则表达式匹配
 */
using System;
// public class IsMatchSolution
public class Solution
{
    public bool IsMatch(string s, string p)
    {
        if (string.IsNullOrEmpty(p) && string.IsNullOrEmpty(s))
        {
            return true;
        }
        if (string.IsNullOrEmpty(p) && !string.IsNullOrEmpty(p))
        {
            return false;
        }
        int i = 0, j = 0;
        for (; i < p.Length; i++)
        {
            if (j >= s.Length)
            {
                return false;
            }
            // 第一个不相等，第二个为*
            if (i + 1 < p.Length && p[i] != s[j] && p[i + 1] == '*' && p[i] != '.')
            {
                i += 2;
            }
            if (i >= p.Length)
            {
                return false;
            }

            if (p[i] == s[j])
            {
                j++;
            }
            else if (p[i] == '.')
            {
                j++;
            }
            else if (p[i] == '*')
            {
                if (i == 0)
                {
                    return false;
                }
                while (j < p.Length && (p[i - 1] == s[j] || p[i - 1] == '.'))
                {
                    j++;
                }
            }
            else
            {
                return false;
            }
        }
        return j == (s.Length) && i == (p.Length);
    }
    public void Test()
    {
        Console.WriteLine("s:aa|p:a    " + IsMatch("aa", "a"));
        Console.WriteLine("s:aa|p:a*   " + IsMatch("aa", "a*"));
        Console.WriteLine("s:aa|p:.*   " + IsMatch("aa", ".*"));
        Console.WriteLine("s:aab|p:c*a*b   " + IsMatch("aab", "c*a*b"));
        Console.WriteLine("s:mississippi|p:mis*is*p*.  " + IsMatch("mississippi", "mis*is*p*."));
    }
}

