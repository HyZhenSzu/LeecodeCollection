#include <iostream>
#include <vector>
#include <queue>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (root == nullptr)
        return nullptr;
    std::queue<Node *> q;
    q.push(root);
    int levelSize = 1;
    while (!q.empty())
    {
        while (levelSize > 0)
        {
            levelSize--;
            Node *temp = q.front();
            q.pop();
            if (levelSize > 0)
                temp->next = q.front();
            else
                temp->next = nullptr;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        levelSize = q.size();
    }
    return root;
}