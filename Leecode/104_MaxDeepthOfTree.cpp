// 给定一个二叉树 root ，返回其最大深度。
// 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。


// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：3

// 示例 2：
// 输入：root = [1,null,2]
// 输出：2

#include <iostream>
#include <stack>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void CreateTreeInPreOrder(std::vector<int>& list, int index, TreeNode* &node){
    if(index >= list.size() || list[index] == -1)
        return;

    node = new TreeNode(list[index]);
    CreateTreeInPreOrder(list, index * 2 + 1, node->left);
    CreateTreeInPreOrder(list, index * 2 + 2, node->right);
}

void PrintTreeInPreOrder(TreeNode* node){
    if(node == nullptr)
        return;
    std::cout << node->val << " ";
    PrintTreeInPreOrder(node->left);
    PrintTreeInPreOrder(node->right);
}

int maxDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    std::vector<int> list = {3,9,20,-1,-1,15,7};
    TreeNode* root = nullptr;
    CreateTreeInPreOrder(list, 0, root);
    PrintTreeInPreOrder(root);
    std::cout << std::endl;
    std::cout << maxDepth(root) << std::endl;

    return 0;
}