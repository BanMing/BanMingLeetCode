/******************************************************************
** 文件名: IsNumber.cpp
** 创建人: BanMing 
** 日  期: 6/7/2020, 10:52:40 PM
** 描  述:  这道题太坑了

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

#include <iostream>

class Solution
{
public:
    bool isNumber(std::string s)
    {
        bool isHaveDot = false;
        for (size_t i = 0; i < s.size(); i++)
        {
            if ((s[i] == '-' || s[i] == '+') && i != 0)
            {
                return false;
            }

            if (s[i] == '.')
            {
                if (isHaveDot)
                {
                    return false;
                }
                isHaveDot = true;
            }

            if (s[i] == 'e' && (i == 0 || i == s.size() - 1))
            {
                return false;
            }
            if (s[i] < '0' || s[i] > '9')
            {
                return false;
            }
        }

        return true;
    }
};

void Run()
{
    Solution solution;
    std::cout << solution.isNumber("1 ") << std::endl;
    // bool isOk = 'a' > 9;
    // cout << isOk << endl;
    // printf("%d \n", 'e');
    // printf("%d \n", '9');
}