/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty() || s.empty())
        {
            return false;
        }
        int i = 0, j = 0;

        while (i < s.length())
        {
            if (s[i] == p[j])
            {
                i++;
                j++;
            }

            cout << s[i] << endl;
            i++;
        }

        return s.compare(p) == 0;
    }
};

void Run()
{
    Solution solution;
    cout << solution.isMatch("aa", "a") << endl;
    // cout << solution.isMatch("aa", "a*") << endl;
    // cout << solution.isMatch("ab", ".*") << endl;
    // cout << solution.isMatch("aab", "c*a*b") << endl;
    // cout << solution.isMatch("mississippi", "mis*is*p*.") << endl;
}
// @lc code=end
