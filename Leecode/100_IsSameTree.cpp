#include <iostream>
#include <queue>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    std::queue<TreeNode*> q1, q2;
    q1.push(p);
    q2.push(q);
    while(!q1.empty() && !q2.empty())
    {
        TreeNode* node1 = q1.front();
        TreeNode* node2 = q2.front();
        q1.pop();
        q2.pop();
        if(node1 == nullptr && node2 == nullptr)
        {
            continue;
        }
        else if(node1 == nullptr || node2 == nullptr)
        {
            return false;
        }
        {
            if(node1->val != node2->val)
            {
                return false;
            }

            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }
    }
    return true;
}