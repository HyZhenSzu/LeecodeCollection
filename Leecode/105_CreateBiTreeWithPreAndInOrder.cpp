#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreePreAndInOrder(std::vector<int>& preorder, std::vector<int>& inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
    if(inBegin > inEnd || preBegin > preEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[preBegin]);
    int rootPos = inBegin;
    while(rootPos <= inEnd)
    {
        if(preorder[preBegin] == inorder[rootPos])
            break;
        rootPos++;
    }
    root->left = buildTreePreAndInOrder(preorder, inorder, preBegin + 1, preBegin + rootPos - inBegin, inBegin, rootPos - 1);
    root->right = buildTreePreAndInOrder(preorder, inorder, preBegin + rootPos - inBegin + 1, preEnd, rootPos + 1, inEnd);
    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if(preorder.empty() || inorder.empty()) return nullptr;
    return buildTreePreAndInOrder(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}