/*
 * @lc app=leetcode.cn id=14 lang=csharp
 *
 * [14] 最长公共前缀
 */
public class LongestCommonPrefixSolution
// public class Solution
{
    public string LongestCommonPrefixSelf(string[] strs)
    {
        if (strs.Length < 1)
        {
            return "";
        }
        if (strs.Length == 1)
        {
            return strs[0];
        }
        string res = "";
        bool isFinish = false;
        for (int i = 0; i < strs[0].Length; i++)
        {
            var compare = res + strs[0][i];
            for (int j = 1; j < strs.Length; j++)
            {
                if (!strs[j].StartsWith(compare))
                {
                    isFinish = true;
                    break;
                }
            }
            if (isFinish)
            {
                break;
            }
            else
            {
                res = compare;
            }

        }

        return res;
    }
    public string LongestCommonPrefix(string[] strs)
    {
        var res = "";

        return res;
    }
    public void Test()
    {
        System.Console.WriteLine("[\"flower\",\"flow\",\"flight\"]:" + LongestCommonPrefix(new string[] { "flower", "flow", "flight" }));
        System.Console.WriteLine("[\"flower\",\"dog\",\"flight\"]:" + LongestCommonPrefix(new string[] { "flower", "dog", "flight" }));
    }
}

