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
            if (isSameChar(s[i], p[j]))
            {
                j++;
            }
            else if (p[j] == '*')
            {
                if (j > 0 && isSameChar(s[i], p[j - 1]))
                {
                    j++;
                }
                else if (j < p.length() && isSameChar(s[i], p[j - 1]))
                {
                    j += 2;
                }
            }

            i++;
        }
        return i == j;
    }
    bool isSameChar(char s, char p)
    {
        return s == p || p == '.';
    }
};

void Run()
{
    Solution solution;
    cout << to_string(solution.isMatch("aa", ".a.")) << endl;
    // cout << solution.isMatch("aa", "a*") << endl;
    // cout << solution.isMatch("ab", ".*") << endl;
    // cout << solution.isMatch("aab", "c*a*b") << endl;
    // cout << solution.isMatch("mississippi", "mis*is*p*.") << endl;
}
// @lc code=end
