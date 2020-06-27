/******************************************************************
** 文件名: MirrorTree.cpp
** 创建人: BanMing 
** 日  期: 6/27/2020, 4:18:19 PM
** 描  述:  剑指 Offer 27. 二叉树的镜像
https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>

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
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;

        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);

        return root;
    }
};

void Run()
{
    // [1,0,1,-4,-3]
    // [1,-4]
    TreeNode treeA(1);

    treeA.left = new TreeNode(0);
    treeA.right = new TreeNode(1);

    treeA.left->left = new TreeNode(-4);
    treeA.left->right = new TreeNode(-3);

    Solution solution;
    solution.mirrorTree(&treeA);
}