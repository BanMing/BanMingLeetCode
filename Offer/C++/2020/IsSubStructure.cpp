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

        return true;
    }

private:
    vector<int> preOrder(TreeNode *tree)
    {
        stack<TreeNode *> treeStack;
        while (tree != NULL || !treeStack.empty())
        {

            while (tree != NULL)
            {
                treeStack.push(tree);
                printf("cur node : %d \n", tree->val);
                tree = tree->left;
            }

            if (!treeStack.empty())
            {
                TreeNode *top = treeStack.top();
                treeStack.pop();
                tree = top->right;
            }
        }
    }
};

void Run()
{
    Solution solution;

    TreeNode treeA(1);
    treeA.left = new TreeNode(2);
    treeA.right = new TreeNode(3);
    treeA.left->left = new TreeNode(4);
    treeA.left->right = new TreeNode(5);
    solution.isSubStructure(&treeA, nullptr);
}