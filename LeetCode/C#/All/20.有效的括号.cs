/*
 * @lc app=leetcode.cn id=20 lang=csharp
 *
 * [20] 有效的括号
 */

// @lc code=start
using System;
using System.Collections.Generic;
// public class Solution
public class IsValidSolution
{
    Dictionary<char, char> leftDic = new Dictionary<char, char>() { { '{', '}' }, { '[', ']' }, { '(', ')' } };
    public bool IsValid(string s)
    {
        Stack<char> res = new Stack<char>();
        for (int i = 0; i < s.Length; i++)
        {
            if (res.Count == 0)
            {
                res.Push(s[i]);
            }
            else if (leftDic[res.Peek()] == s[i])
            {
                res.Pop();
            }
            else
            {
                res.Push(s[i]);
            }

        }
        return res.Count == 0;
    }
    public void Test()
    {
        // IsValid("(([]){})");
        IsValid("([)]");
    }
}
// @lc code=end

