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

    public string LongestPalindrome1(string s)
    // public string LongestPalindrome(string s)
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

    public string LongestPalindrome(string str)
    // public string dpTableLongestPalindrome(string str)
    {
        if (string.IsNullOrEmpty(str) || str.Length < 2)
        {
            return str;
        }
        // 计算长度为2的回文
        if (str.Length < 3)
        {
            if (str[0] == str[1])
            {
                return str;
            }
            else
            {
                return str[0].ToString();
            }
        }
        bool[][] dp = new bool[str.Length][];
        int start = 0;
        int maxLength = 1;
        // 计算长度为1和2的回文字符串即为相同
        for (int i = 0; i < str.Length; i++)
        {
            dp[i] = new bool[str.Length];
            dp[i][i] = true;
            if (i + 1 < str.Length && str[i] == str[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // 计算大于2的回文 i表示检测回文长度
        for (int i = 3; i <= str.Length; i++)
        {
            // j表示开始的index ,m表示结束index
            for (int j = 0; j + i - 1 < str.Length; j++)
            {
                int m = j + i - 1;
                // 新的两端相同以及长度减2的是回文即这个也是回文babad
                // int x = j + 1 < 0 ? 0 : j - 1;
                // int y = m > str.Length ? str.Length - 1 : m;
                if (str[j] == str[m] && j + 1 < str.Length && m - 1 >= 0 && dp[j + 1][m - 1])
                {
                    dp[j][m] = true;
                    if (i > maxLength)
                    {
                        maxLength = i;
                        start = j;
                    }
                }
            }
        }
        return str.Substring(start, maxLength);
    }


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
        // System.Console.WriteLine((longest.LongestPalindrome("babad")));
        // System.Console.WriteLine((longest.dpTableLongestPalindrome("babad")));
        // System.Console.WriteLine((longest.LongestPalindrome("cbbd")));
        // System.Console.WriteLine((longest.dpTableLongestPalindrome("cbbd")));
        // System.Console.WriteLine((longest.LongestPalindrome("bb")));
        // System.Console.WriteLine((longest.dpTableLongestPalindrome("bb")));
        System.Console.WriteLine((longest.LongestPalindrome("ccc")));
    }
}


// }

// @lc code=end

