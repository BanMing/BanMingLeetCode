/******************************************************************
** 文件名: VerifyPostorder.cpp
** 创建人: BanMing 
** 日  期: 7/7/2020, 8:16:29 AM
** 描  述:  剑指 Offer 33. 二叉搜索树的后序遍历序列
https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> Postorder;
    bool verifyPostorder(vector<int> &postorder)
    {
        if (postorder.empty())
        {
            return true;
        }

        Postorder = postorder;
        return recur(0, postorder.size() - 1);
    }
    bool recur(int startIndex, int endIndex)
    {
        if (startIndex >= endIndex)
        {
            return true;
        }

        int rootVal = Postorder[endIndex];
        int p = startIndex;
        // 找到比根节点大的位置 之前都为左子树
        while (Postorder[p] < rootVal)
        {
            p++;
        }

        // 判断右子树的值是否都比根节点大
        int m = p;
        while (Postorder[p] > rootVal)
        {
            p++;
        }

        return p == endIndex && recur(startIndex, m - 1) && recur(m, endIndex - 1);
    }

    bool verifyPostorderSelf(vector<int> &postorder)
    {
        if (postorder.empty())
        {
            return false;
        }

        Postorder = postorder;
        int rootVal = postorder[postorder.size() - 1];
        int m = 0;
        while (postorder[m] < rootVal)
        {
            m++;
        }
        if (m == 0)
        {
            return true;
        }
        if (m == postorder.size())
        {
            return false;
        }
        return recursion(0, m, postorder.size() - 1);
    }

    bool recursion(int leftIndex, int middleIndex, int rootIndex)
    {
        if (leftIndex == middleIndex - 1 && middleIndex + 1 == rootIndex)
        {
            return true;
        }
        if (middleIndex == rootIndex || middleIndex == leftIndex)
        {
            return false;
        }

        int leftM = leftIndex;
        // 左子树
        while (Postorder[leftM] < Postorder[middleIndex - 1])
        {
            leftM++;
        }

        // 右子树
        int rightM = middleIndex;
        while (Postorder[rightM] < Postorder[rootIndex - 1])
        {
            rightM++;
        }

        return recursion(leftIndex, leftM, middleIndex - 1) && recursion(middleIndex, rightM, rootIndex - 1);
    }
};

void Run()
{
    Solution solution;
    int testArray[] = {4, 6, 7, 5};
    vector<int> test(testArray, testArray + 4);
    printf(" %d \n", solution.verifyPostorder(test));
}