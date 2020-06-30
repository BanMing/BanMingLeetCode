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

        if (matrix.empty())
        {
            return res;
        }

        size_t lenI = matrix.size();
        size_t lenJ = matrix[0].size();
        size_t totalCount = lenI * lenJ;
        int i = 0, j = 0;
        int minI = 0, minJ = 0;
        while (res.size() < totalCount && minI < lenI && minJ < lenJ)
        {
            i = minI, j = minJ;
            // if (i == minI && j == minJ)
            // {

            // }
            while (j < lenJ)
            {
                res.push_back(matrix[i][j]);
                j++;
            }
            minI++;
            if (i < lenI && j == lenJ && i + 1 < lenI)
            {
                j--;
                i++;
                while (i < lenI)
                {
                    res.push_back(matrix[i][j]);
                    i++;
                }
                lenJ--;
            }
            if (i == lenI && j == lenJ && j - 1 >= minJ)
            {
                i--;
                j--;
                while (j >= minJ)
                {
                    res.push_back(matrix[i][j]);
                    j--;
                }
                lenI--;
            }
            if (i == lenI && j == minJ - 1 && i - 1 >= minI)
            {
                i--;
                j++;
                while (i >= minI)
                {
                    res.push_back(matrix[i][j]);
                    i--;
                }
                minJ++;
            }
        }

        return res;
    }
};

void Run()
{
    vector<vector<int>> test = {{1, 2, 3, 11, 14}, {1, 2, 3, 4, 5}, {4, 5, 6, 12, 15}, {7, 8, 9, 13, 16}};
    Solution solution;
    solution.spiralOrder(test);
}