/*
 * @lc app=leetcode.cn id=5 lang=csharp
 *
 * [5] 最长回文子串
 */

// @lc code=start
// namespace In2020
// {
//     public class LongestPalindromeSolution
public class Solution
{

    public string LongestPalindrome(string s)
    {
        if (string.IsNullOrEmpty(s) || s.Length < 2)
        {
            return s;
        }
        int startIndex = 0;
        int maxLength = 1;
        for (int i = 0; i < s.Length; i++)
        {
            int start = i;
            int end = i;
            // 向后移动相同中心块服
            while (end + 1 < s.Length && s[start] == s[end + 1])
            {
                end++;
            }

            // 两边指针移动
            while (start - 1 >= 0 && end + 1 < s.Length && s[start - 1] == s[end + 1])
            {
                start--;
                end++;
            }
            if (end - start + 1 > maxLength)
            {

                maxLength = end - start + 1;
                startIndex = start;
            }

        }
        return s.Substring(startIndex, maxLength);
    }
    // TODO ：动态规划不会
    #region self
    public string SelfLongestPalindrome(string s)
    {
        if (string.IsNullOrEmpty(s) || s.Length < 2)
        {
            return s;
        }
        System.Collections.Generic.Dictionary<int, int> dp = new System.Collections.Generic.Dictionary<int, int>();
        string res = string.Empty;
        for (int i = 0; i < s.Length; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string newStr = s.Substring(j, i - j + 1);
                if (isReverseStr(newStr))
                {
                    res = newStr.Length > res.Length ? newStr : res;
                }
            }
        }
        return res.Equals(string.Empty) ? s[0].ToString() : res;
    }
    private bool isReverseStr(string str)
    {
        System.Text.StringBuilder newStr = new System.Text.StringBuilder();
        for (int i = str.Length - 1; i >= 0; i--)
        {
            newStr.Append(str[i]);
        }
        return newStr.Equals(str);
    }
    #endregion
    public static void Run()
    {
        Solution longest = new Solution();
        System.Console.WriteLine((longest.LongestPalindrome("babad")));
        // System.Console.WriteLine((longest.LongestPalindrome("cbbd")));
        // System.Console.WriteLine((longest.LongestPalindrome("bb")));
    }
}


// }

// @lc code=end

