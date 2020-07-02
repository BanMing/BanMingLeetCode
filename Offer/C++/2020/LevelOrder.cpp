// 剑指 Offer 32 - I. 从上到下打印二叉树
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/

#include <iostream>
#include <queue>
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
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }

        res.push_back(root->val);
        queue<TreeNode *> temp;
        while (root)
        {
            if (root->left)
            {
                temp.push(root->left);
                res.push_back(root->left->val);
            }
            if (root->right)
            {
                temp.push(root->right);
                res.push_back(root->right->val);
            }
            if (!temp.empty())
            {
                root = temp.front();
                temp.pop();
            }
            else
            {
                root = NULL;
            }
        }
        return res;
    }
};

void Run()
{
    // 3,9,20,null,null,15,7
    TreeNode treeA(3);

    treeA.left = new TreeNode(9);
    treeA.right = new TreeNode(20);

    // treeA.left->left = new TreeNode(-4);
    // treeA.left->right = new TreeNode(-3);

    treeA.right->right = new TreeNode(15);
    treeA.right->left = new TreeNode(7);

    Solution solution;
    solution.levelOrder(&treeA);
}