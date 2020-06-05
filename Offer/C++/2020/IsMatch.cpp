/******************************************************************
** 文件名: IsMatch.cpp
** 创建人: BanMing 
** 日  期: 6/4/2020, 8:25:39 AM
** 描  述:  面试题19. 正则表达式匹配

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.empty() || p.empty())
        {
            return false;
        }

        vector<vector<bool> > dp(s.size());
        for (size_t i = 0; i < s.size(); i++)
        {
            dp[i].resize(p.size());
            for (size_t j = 0; j < p.size(); j++)
            {
                dp[i][j] = false;
            }
        }

        dp[0][0] = s[0] == p[0] || p[0] == '.';

        for (size_t i = 1; i < s.empty(); i++)
        {
            for (size_t j = 1; j < p.empty(); j++)
            {
                bool isEqual = (p[j] == '.' || s[i] == p[i]) && dp[i - 1][j - 1];
                if (p[j] == '*')
                {
                    bool noContains = j > 1 && dp[i][j - 2];
                    bool isOneMore = (p[j - 1] == s[i] || p[j - 1] == '.') && dp[i - 1][j];
                    isEqual = isEqual || noContains || isOneMore;
                }
                dp[i][j] = isEqual;
            }
        }
        return dp[s.size()][p.size()];
    }
};
void Run()
{
}