// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
// 剑指 Offer 34. 二叉树中和为某一值的路径

#include <iostream>
#include <math.h>
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
    vector<int> path;
    vector<vector<int> > res;

    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        res.clear();
        recur(root, sum);
        return res;
    }

    void recur(TreeNode *node, int tar)
    {
        if (node == NULL)
        {
            return;
        }
        tar -= node->val;
        path.push_back(node->val);

        // 终止：和为sum与当前是尾节点
        if (tar == 0 && node->left == NULL && node->right == NULL)
        {
            res.push_back(path);
            // path.clear();
            path.pop_back();
            return;
        }

        recur(node->left, tar);
        recur(node->right, tar);

        path.pop_back();
    }

    vector<vector<int> > pathSumSelf(TreeNode *root, int sum)
    {
        vector<vector<int> > res;

        if (root == NULL)
        {
            return res;
        }

        int num = sum - root->val;
        if (sum == 0)
        {
            return res;
        }

        pathSum(root->left, num);
        pathSum(root->right, num);

        return res;
    }
};

void Run()
{
    // [5,4,8,11,null,13,4,7,2,null,null,5,1]
    TreeNode treeA(5);

    treeA.left = new TreeNode(4);
    treeA.right = new TreeNode(8);

    treeA.left->left = new TreeNode(11);
    // treeA.left->right = new TreeNode(-3);

    treeA.right->left = new TreeNode(13);
    treeA.right->right = new TreeNode(4);

    treeA.left->left->left = new TreeNode(7);
    treeA.left->left->right = new TreeNode(2);

    treeA.right->right->left = new TreeNode(5);
    treeA.right->right->right = new TreeNode(1);

    Solution solution;
    solution.pathSum(&treeA, 22);
}