/*
 * @lc app=leetcode.cn id=3 lang=csharp
 *
 * [3] 无重复字符的最长子串
 */
using System;
using System.Collections.Generic;
// public class LengthOfLongestSubstringSolution
public class Solution

{
    public int LengthOfLongestSubstringSelf(string s)
    {
        int maxLen = 1;
        string resStr = "";
        for (int i = 0; i < s.Length; i++)
        {
            if (!resStr.Contains(s[i]))
            {
                resStr += s[i];
            }
            else
            {
                resStr = resStr.Substring(resStr.IndexOf(s[i]) + 1) + s[i];
            }
            maxLen = Math.Max(resStr.Length, maxLen);
        }
        return maxLen;
    }
    public int LengthOfLongestSubstring(string s)
    {
        var charDict = new Dictionary<char, int>();
        int startIndex = 0;
        int maxLen = 0;
        int curCount = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (!charDict.ContainsKey(s[i]))
            {
                charDict.Add(s[i], i);
                curCount++;
            }
            else
            {
                if (startIndex <= charDict[s[i]])
                {
                    startIndex = charDict[s[i]];
                    charDict[s[i]] = i;
                }
                else
                {
                    // 重复点前面废弃得值
                    charDict[s[i]] = i;
                    curCount++;
                }
                curCount = i - startIndex;
            }
            maxLen = Math.Max(maxLen, curCount);
        }
        return maxLen;
    }
    public void Test()
    {
        System.Console.WriteLine("abcabcbb:" + LengthOfLongestSubstring("abcabcbb"));
        System.Console.WriteLine("bbbbb:" + LengthOfLongestSubstring("bbbbb"));
        System.Console.WriteLine("pwwkew:" + LengthOfLongestSubstring("pwwkew"));
        System.Console.WriteLine("aabaab!bb:" + LengthOfLongestSubstring("aabaab!bb"));
        // System.Console.WriteLine("\'\" \"\':" + LengthOfLongestSubstring("\'\" \"\'"));
    }
}

