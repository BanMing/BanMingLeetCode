/*
 * @lc app=leetcode.cn id=10 lang=csharp
 *
 * [10] 正则表达式匹配
 */
using System;
using System.Collections.Generic;
// public class IsMatchSolution
public class Solution
{
    public bool IsMatchSelf(string s, string p)
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
                while (j < s.Length && (p[i - 1] == s[j] || p[i - 1] == '.'))
                {
                    if (j + 1 < s.Length && i + 1 < p.Length && s[j + 1] == p[i + 1])
                    {
                        i++;
                        j++;
                    }
                    if (i + 1 < p.Length && p[i] != s[j] && p[i + 1] == '*' && p[i] != '.')
                    {
                        i += 2;
                    }
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

    public bool IsMatch(string s, string p)
    {
        // 动态规划
        var dp = new bool[s.Length + 1][];
        for (int i = 0; i < s.Length + 1; i++)
        {
            dp[i] = new bool[p.Length + 1];
        }
        dp[0][0] = true;

        for (int i = 0; i <= s.Length; i++)
        {
            for (int j = 1; j <= p.Length; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[s.Length][p.Length];
        // return false;
    }

    public void Test()
    {
        // Console.WriteLine("s:aa|p:a    " + IsMatch("aa", "a"));
        Console.WriteLine("s:aa|p:a*   " + IsMatch("aa", "a*"));
        // Console.WriteLine("s:aa|p:.*   " + IsMatch("aaa", ".*"));
        // Console.WriteLine("s:aab|p:c*a*b   " + IsMatch("aab", "c*a*b"));
        // Console.WriteLine("s:mississippi|p:mis*is*p*.  " + IsMatch("mississippi", "mis*is*p*."));
        // Console.WriteLine("s:ab|p:.*c  " + IsMatch("ab", ".*c"));
        // Console.WriteLine("s:aaa|p:a*a " + IsMatch("aaa", "a*a"));
        // Console.WriteLine("s:aaa|p:ab*a*c*a " + IsMatch("aaa", "ab*a*c*a"));
    }
}

