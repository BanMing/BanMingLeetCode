// 剑指 Offer 26. 树的子结构
// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
#include <iostream>
#include <stack>
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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (B == NULL || A == NULL)
        {
            return false;
        }

        return isEqual(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool isEqual(TreeNode *A, TreeNode *B)
    {
        if (B == NULL)
        {
            return true;
        }
        if (A == NULL)
        {
            return false;
        }
        return A->val == B->val && isEqual(A->left, B->left) && isEqual(A->right, B->right);
    }

    bool isSubStructureSelf(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr || A == nullptr)
        {
            return false;
        }

        vector<int> a = preOrder(A);
        vector<int> b = preOrder(B);
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] == b[0])
            {
                size_t m = i + 1;
                for (size_t j = 1; j < b.size(); j++)
                {
                    if (m >= a.size() || a[m] != b[j])
                    {
                        break;
                    }
                    m++;
                }
                if (m - i == b.size())
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    vector<int> preOrder(TreeNode *tree)
    {
        stack<TreeNode *> treeStack;
        vector<int> res;
        while (tree != NULL || !treeStack.empty())
        {

            while (tree != NULL)
            {
                treeStack.push(tree);
                printf("cur node : %d \n", tree->val);
                res.push_back(tree->val);
                tree = tree->left;
            }

            if (!treeStack.empty())
            {
                TreeNode *top = treeStack.top();
                treeStack.pop();
                tree = top->right;
            }
        }
        return res;
    }
};

void Run()
{
    Solution solution;

    // [1,0,1,-4,-3]
    // [1,-4]
    TreeNode treeA(1);

    treeA.left = new TreeNode(0);
    treeA.right = new TreeNode(1);

    treeA.left->left = new TreeNode(-4);
    treeA.left->right = new TreeNode(-3);

    // treeA.right->left = new TreeNode(11);

    TreeNode treeB(-4);

    // treeB.left = new TreeNode(-4);
    // treeB.right = new TreeNode(6);

    // treeB.left->left = new TreeNode(8);
    printf("isSubStructure %d \n", solution.isSubStructure(&treeA, &treeB));
}