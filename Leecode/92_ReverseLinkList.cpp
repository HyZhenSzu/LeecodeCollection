// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

// 示例 1：
// 输入：head = [1,2,3,4,5], left = 2, right = 4
// 输出：[1,4,3,2,5]

// 示例 2：
// 输入：head = [5], left = 1, right = 1
// 输出：[5]

#include <iostream>
#include <vector>

 struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head == nullptr) return nullptr;
    if(left == right) return head;

    int pos = 0;
    ListNode *temp = head;
    while(temp != nullptr && pos < left - 1)
    {
        temp = temp->next;
        pos++;
    }
    ListNode *leftNode = temp;
    std::vector<int> nodes;
    while(temp != nullptr && pos < right)
    {
        nodes.push_back(temp->val);
        temp = temp->next;
        pos++;
    }
    for (auto it = nodes.rbegin(); it != nodes.rend(); it++)
    {
        leftNode->val = *it;
        leftNode = leftNode->next;
    }
    return head;
}
 