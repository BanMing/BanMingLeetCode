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
#include <map>
#include <stack>
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
    // self solution
    TreeNode *buildTreeSelf(vector<int> &preorder, vector<int> &inorder)
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

    // recursion solution
    map<int, int> inorderMap;
    vector<int> Preorder;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (size_t i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        Preorder = preorder;

        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *build(int preStartIndex, int preEndIndex, int inStartIndex, int inEndIndex)
    {
        if (preStartIndex > preEndIndex)
        {
            return NULL;
        }

        int rootVal = Preorder[preStartIndex];
        TreeNode *root = new TreeNode(rootVal);
        if (preStartIndex == preEndIndex)
        {
            return root;
        }
        else
        {
            int inOrderRootIndex = inorderMap[rootVal];
            int letfNodeCount = inOrderRootIndex - inStartIndex;
            int rightNodeCount = inEndIndex - inOrderRootIndex;

            root->left = build(preStartIndex + 1, preStartIndex + letfNodeCount, inStartIndex, inOrderRootIndex - 1);
            root->right = build(preEndIndex - rightNodeCount + 1, preEndIndex, inOrderRootIndex + 1, inEndIndex);

            return root;
        }
    }

    // loop solution fuck error!!!!!!!!!!!1
    TreeNode *buildTreeLoop(vector<int> &preorder, vector<int> &inorder)
    {
        int rootVal = preorder[0];
        TreeNode *tree = new TreeNode(rootVal);

        TreeNode *res = tree;

        stack<int> treeStack;
        int index = 0;
        while (rootVal != inorder[index] && inorder.size() > index)
        {
            treeStack.push(inorder[index]);
            index++;
        }

        if (treeStack.size() > 0)
        {
            int left = treeStack.top();
            tree->left = new TreeNode(left);
        }
        int right = preorder[1 + treeStack.size()];
        tree->right = new TreeNode(right);

        return res;
    }
};
void Run()
{
    Solution solution;
    int preOrders[] = {1, 2}; //{3, 9, 20, 15, 7};
    vector<int> preOrder(preOrders, preOrders + 5);

    int inOrders[] = {1, 2}; //{9, 3, 15, 20, 7};
    vector<int> inOrder(inOrders, inOrders + 2);
    TreeNode *res = solution.buildTree(preOrder, inOrder);
    printf("end");
}