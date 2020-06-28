// 剑指 Offer 28. 对称的二叉树
// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
        {
            return true;
        }
        if (left == NULL || right == NULL)
        {
            return false;
        }

        return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

void Run()
{

    TreeNode treeA(1);

    treeA.left = new TreeNode(1);
    treeA.right = new TreeNode(1);

    treeA.left->left = new TreeNode(-4);
    treeA.left->right = new TreeNode(-3);

    treeA.right->left = new TreeNode(-3);
    // treeA.right->right = new TreeNode(-4);

    Solution solution;
    printf("[1,0,1,-4,-3] = %d \n", solution.isSymmetric(&treeA));
    // printf("[1,1,1,-4,-3,-3,-4] = %d \n", solution.isSymmetric(&treeA));
}