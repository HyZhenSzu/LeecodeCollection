#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSame(TreeNode* left, TreeNode* right) {
    if(left == nullptr && right == nullptr) return true;
    if(left == nullptr || right == nullptr) return false;
    if(left->val != right->val) return false;

    return isSame(left->left, right->right) && isSame(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return isSame(root->left, root->right);
}