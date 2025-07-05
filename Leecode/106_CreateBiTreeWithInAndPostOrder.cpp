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

TreeNode* buildTreeInAndPost(std::vector<int>& inorder, std::vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd) {
    if(inBegin > inEnd || postBegin > postEnd) return nullptr;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    int rootPos = inBegin;
    while(rootPos <= inEnd)
    {
        if(postorder[postEnd] == inorder[rootPos])
            break;
        rootPos++;
    }
    root->left = buildTreeInAndPost(inorder, postorder, inBegin, rootPos - 1, postBegin, postBegin + rootPos - inBegin - 1);
    root->right = buildTreeInAndPost(inorder, postorder, rootPos + 1, inEnd, postBegin + rootPos - inBegin, postEnd - 1);
    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    if(inorder.empty() || postorder.empty()) return nullptr;
    return buildTreeInAndPost(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}