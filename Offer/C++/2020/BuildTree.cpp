/******************************************************************
** 文件名: BuildTree.cpp
** 创建人: BanMing 
** 日  期: 5/24/2020, 9:43:42 PM
** 描  述:  重建二叉树
https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
        {
            return NULL;
        }

        TreeNode *tree = new TreeNode(preorder[0]);

        vector<int> leftInNodes;
        vector<int> leftPreNodes;

        vector<int> rightInNodes;
        vector<int> rightPreNodes;

        int rootIndex = -1;
        for (size_t i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
            {
                rootIndex = i;
            }

            if (rootIndex == -1 && inorder[i] != preorder[0])
            {
                leftInNodes.push_back(inorder[i]);
            }
            else if (rootIndex != -1 && inorder[i] != preorder[0])
            {
                rightInNodes.push_back(inorder[i]);
            }
        }

        for (size_t i = 1; i < preorder.size(); i++)
        {
            if (leftPreNodes.size() < leftInNodes.size())
            {
                leftPreNodes.push_back(preorder[i]);
            }
            else
            {
                rightPreNodes.push_back(preorder[i]);
            }
        }

        tree->left = buildTree(leftPreNodes, leftInNodes);
        tree->right = buildTree(rightPreNodes, rightInNodes);
        return tree;
    }
};
void Run()
{
    Solution solution;
    int preOrders[] = {1, 2}; //{3, 9, 20, 15, 7};
    vector<int> preOrder(preOrders, preOrders + 5);

    int inOrders[] = {1, 2}; //{9, 3, 15, 20, 7};
    vector<int> inOrder(inOrders, inOrders + 5);
    TreeNode *res = solution.buildTree(preOrder, inOrder);
    printf("end");
}