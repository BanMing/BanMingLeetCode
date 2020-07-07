/******************************************************************
** 文件名: LevelOrder3.cpp
** 创建人: BanMing 
** 日  期: 7/7/2020, 7:34:40 AM
** 描  述:  剑指 Offer 32 - III. 从上到下打印二叉树 III
https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > res;
        if (root == NULL)
        {
            return res;
        }

        queue<TreeNode *> nodeQueue;
        vector<int> temp;
        bool flag = true;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            temp.clear();
            flag = !flag;
            size_t len = nodeQueue.size();
            for (size_t i = 0; i < len; i++)
            {
                TreeNode *curNode = nodeQueue.front();
                temp.insert(flag ? temp.begin() : temp.end(), curNode->val);
                if (curNode->left != NULL)
                {
                    nodeQueue.push(curNode->left);
                }
                if (curNode->right != NULL)
                {
                    nodeQueue.push(curNode->right);
                }
                nodeQueue.pop();
            }
            res.push_back(temp);
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