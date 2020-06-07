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

        vector<vector<bool> > dp(s.size() + 1);
        for (size_t i = 0; i < s.size() + 1; i++)
        {
            dp[i].resize(p.size() + 1);
            for (size_t j = 0; j < p.size() + 1; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = i == 0;
                }
                else
                {

                    bool isEqual = false;
                    if (p[j - 1] != '*')
                    {
                        // 不含有*
                        isEqual = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                    }
                    else
                    {
                        // 含有* *为0表示
                        isEqual = isEqual || (j >= 2 && dp[i][j - 2]);

                        // 含有* *为多个或1个
                        isEqual = isEqual || (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                    }
                    dp[i][j] = isEqual;
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};
void Run()
{
    Solution solution;
    printf("s=aa p = a isMacth %d \n", solution.isMatch("aa", "a"));
    printf("s=aa p = a* isMacth %d \n",solution.isMatch("aa","a*"));
    printf("s=ab p = .* isMacth %d \n",solution.isMatch("aa",".*"));
    printf("s=mississippi p = mis*is*p*. isMacth %d \n",solution.isMatch("mississippi","mis*is*p*."));
}