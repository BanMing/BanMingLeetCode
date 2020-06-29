/******************************************************************
** 文件名: SpiralOrder.cpp
** 创建人: BanMing 
** 日  期: 6/29/2020, 7:29:06 AM
** 描  述:  剑指 Offer 29. 顺时针打印矩阵
https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        size_t lenI = matrix.size();
        size_t lenJ = matrix[0].size();
        int i = 0, j = 0;
        int minI = 0, minJ = 0;
        while (i < lenI || j < lenJ)
        {
            if (i < lenI && j < lenJ)
            {
                while (j < lenJ)
                {
                    res.push_back(matrix[i][j]);
                    j++;
                }
                minI++;
            }
            else if (i < lenI && j == lenJ)
            {
                j--;
                i++;
                while (i < lenI)
                {
                    res.push_back(matrix[i][j]);
                    i++;
                }
            }
            else if (i == lenI && j < lenJ)
            {
                i--;
                j--;
                while (j >= 0)
                {
                    res.push_back(matrix[i][j]);
                    j--;
                }
            }
            else if (i == lenI && j < 0)
            {
                i--;
                j++;
                while (j >= 0)
                {
                    res.push_back(matrix[i][j]);
                    i--;
                }
            }
            minJ++;
            lenJ--;
            lenI--;
        }

        return res;
    }
};

void Run()
{
    vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solution;
    solution.spiralOrder(test);
}