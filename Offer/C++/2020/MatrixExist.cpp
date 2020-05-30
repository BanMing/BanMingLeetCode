/******************************************************************
** 文件名: MatrixExist.cpp
** 创建人: BanMing 
** 日  期: 5/27/2020, 10:43:02 PM
** 描  述:  面试题12. 矩阵中的路径
https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
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
    bool existSelf(vector<vector<char> > &board, string word)
    {
        int horIndex = -1, verIndex = -1, existLen = 0;
        bool isFind;
        for (size_t i = 0; i < word.size(); i++)
        {
            char b = word[i];
            isFind = false;
            for (size_t j = 0; j < board.size(); j++)
            {
                for (size_t k = 0; k < board[0].size(); k++)
                {
                    char a = board[j][k];
                    if (a == b && (horIndex == -1 ||
                                   ((horIndex + 1 == j || horIndex - 1 == j) && verIndex == k) ||
                                   ((verIndex + 1 == k || verIndex - 1 == k) && horIndex == j)))
                    {
                        horIndex = j;
                        verIndex = k;
                        existLen++;
                        isFind = true;
                        break;
                    }
                }
                if (isFind)
                {
                    break;
                }
            }
        }

        return existLen == word.size();
    }
    vector<vector<char> > _borad;
    string _word;
    bool exist(vector<vector<char> > &borad, string word)
    {
        _borad = borad;
        _word = word;
        for (size_t i = 0; i < borad.size(); i++)
        {
            for (size_t j = 0; j < borad[0].size(); j++)
            {
                if (dfs(i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, int k)
    {
        if (i < 0 || i >= _borad.size() || j < 0 || j >= _borad[0].size())
        {
            return false;
        }
        char a = _word[k];
        char b = _borad[i][j];
        if (k >= _word.size() || _word[k] != _borad[i][j])
        {
            return false;
        }
        if (_word.size() - 1 == k)
        {
            return true;
        }

        char temp = _borad[i][j];
        _borad[i][j] = '\\';
        bool res = dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1) || dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1);

        _borad[i][j] = temp;
        return res;
    }
};

void Run()
{
    vector<vector<char> > board(3);
    char test[3][5] = {{'A', 'B', 'C', 'E'},
                       {'S', 'F', 'E', 'S'},
                       {'A', 'D', 'E', 'E'}};
    for (size_t i = 0; i < 3; i++)
    {
        board[i].resize(5);
        for (size_t j = 0; j < 5; j++)
        {
            board[i][j] = test[i][j];
        }
    }
    // char test[1][2] = {
    //     {'a', 'a'},
    // };
    // for (size_t i = 0; i < 1; i++)
    // {
    //     board[i].resize(2);
    //     for (size_t j = 0; j < 2; j++)
    //     {
    //         board[i][j] = test[i][j];
    //     }
    // }

    Solution solution;
    // vector<vector<int> > martix{{5}};
    cout << solution.exist(board, "ABCEE") << endl;
}