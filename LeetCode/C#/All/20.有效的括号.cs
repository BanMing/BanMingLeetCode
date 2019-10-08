/*
 * @lc app=leetcode.cn id=20 lang=csharp
 *
 * [20] 有效的括号
 */

// @lc code=start
using System;
using System.Collections.Generic;
public class Solution
// public class IsValidSolution
{
    Dictionary<char, char> leftDic = new Dictionary<char, char>() { { '{', '}' }, { '[', ']' }, { '(', ')' } };
    public bool IsValid(string s)
    {
        // List<char> res = new List<char>();
        Dictionary<char, int> indexDic = new Dictionary<char, int>();
        for (int i = 0; i < s.Length; i++)
        {

            if (leftDic.ContainsKey(s[i]))
            {
                // res.Add(leftDic[s[i]]);
                if (indexDic.ContainsKey(s[i]))
                {
                    indexDic[leftDic[s[i]]] = i;
                }
                else
                {
                    indexDic.Add(leftDic[s[i]], i);
                }
            }
            else
            {
                // if (res.Contains(s[i]))
                // {
                //     res.RemoveAt(res.IndexOf(s[i]));
                // }
                // else
                // {
                //     return false;
                // }
                if ((i - indexDic[s[i]]) % 2 == 0)
                {
                    indexDic.Remove(s[i]);
                }
                else
                {
                    return false;
                }
            }
        }
        return indexDic.Count == 0;
    }
    public void Test()
    {

    }
}
// @lc code=end

