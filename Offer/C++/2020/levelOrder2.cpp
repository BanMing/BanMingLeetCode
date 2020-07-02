
// 剑指 Offer 32 - II. 从上到下打印二叉树 II
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        qu
    }
};
void Run()
{
    // 3,9,20,null,null,7,15
    TreeNode treeA(3);

    treeA.left = new TreeNode(9);
    treeA.right = new TreeNode(20);

    // treeA.left->left = new TreeNode(-4);
    // treeA.left->right = new TreeNode(-3);

    treeA.right->left = new TreeNode(7);
    treeA.right->right = new TreeNode(15);

    Solution solution;
    solution.levelOrder(&treeA);
}