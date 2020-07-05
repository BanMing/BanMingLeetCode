
// 剑指 Offer 32 - II. 从上到下打印二叉树 II
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    vector<vector<int> >  levelOrderSelf(TreeNode *root)
    {
        vector<vector<int> >  res;
        if (root == NULL)
        {
            return res;
        }

        vector<int> tempVector;
        tempVector.push_back(root->val);
        res.push_back(tempVector);

        tempVector.clear();

        queue<TreeNode *> temp;
        int curCount = 0;
        int lastCount = 1;
        while (root != NULL)
        {
            if (root->left != NULL)
            {
                temp.push(root->left);
                tempVector.push_back(root->left->val);
            }

            if (root->right != NULL)
            {
                temp.push(root->right);
                tempVector.push_back(root->right->val);
            }
            curCount += 2;
            if (!temp.empty())
            {
                root = temp.front();
                temp.pop();
            }
            else
            {
                root = NULL;
            }
            if (curCount == (lastCount * 2))
            {
                lastCount = curCount;
                curCount = 0;
                if (!tempVector.empty())
                {
                    res.push_back(tempVector);
                    tempVector.clear();
                }
            }
        }
        if (!tempVector.empty())
        {
            res.push_back(tempVector);
            tempVector.clear();
        }
        return res;
    }

    vector<vector<int> >  levelOrder(TreeNode *root)
    {
        vector<vector<int> >  res;
        if (root == NULL)
        {
            return res;
        }
        vector<int> temp;

        queue<TreeNode *> lineQueue;
        lineQueue.push(root);
        while (!lineQueue.empty())
        {
            size_t len = lineQueue.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode *curNode = lineQueue.front();
                temp.push_back(curNode->val);

                if (curNode->left != NULL)
                {
                    lineQueue.push(curNode->left);
                }
                if (curNode->right != NULL)
                {
                    lineQueue.push(curNode->right);
                }
                lineQueue.pop();
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
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

    treeA.right->left->left = new TreeNode(8);
    Solution solution;
    solution.levelOrder(&treeA);
}