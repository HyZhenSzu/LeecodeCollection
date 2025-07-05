#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    std::vector<std::vector<int>> result;
    std::queue<TreeNode *> q;
    q.push(root);
    result.push_back({root->val});
    std::vector<int> currentLevel;
    while (!q.empty())
    {
        int levelSize = q.size();
        while (levelSize > 0)
        {
            levelSize--;
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                currentLevel.push_back(temp->left->val);
            }
            if (temp->right)
            {
                q.push(temp->right);
                currentLevel.push_back(temp->right->val);
            }
        }
        if (!currentLevel.empty())
        {
            result.push_back(currentLevel);
            currentLevel.clear();
        }
    }
    return result;
}