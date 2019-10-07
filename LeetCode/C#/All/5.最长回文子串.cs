/*
 * @lc app=leetcode.cn id=5 lang=csharp
 *
 * [5] 最长回文子串
 */
// public class Solution

using System.Collections.Generic;
using System;
public class LongestPalindromeSolution
// public class Solution
{

    public string LongestPalindrome(string s)
    {
        int startIndex = 0, maxLength = 0;
        for (int i = 0; i < s.Length; i++)
        {
            int start = i;
            int end = i;
            // 向后找相同数值，作为中间数值
            while (end < s.Length - 1 && s[start] == s[end + 1])
            {
                end++;
            }
            // 以中间数值向两边查找
            while (start > 0 && end < s.Length - 1 && s[start - 1] == s[end + 1])
            {
                start--;
                end++;
            }
            if (maxLength < end - start + 1)
            {
                maxLength = end - start + 1;
                startIndex = start;
            }
        }
        return s.Substring(startIndex, maxLength);
    }
    public void Test()
    {
        Console.WriteLine("babad:" + LongestPalindrome("babad"));
    }
}

