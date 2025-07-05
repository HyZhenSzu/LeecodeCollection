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

TreeNode* createBSTNodes(std::vector<int>& nums, int start, int end) {
    if(nums.size() == 0) return nullptr;
    if(start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = createBSTNodes(nums, start, mid - 1);
    root->right = createBSTNodes(nums, mid + 1, end);
    return root;
}


TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    if(nums.size() == 0) return nullptr;
    return createBSTNodes(nums, 0, nums.size() - 1);
}