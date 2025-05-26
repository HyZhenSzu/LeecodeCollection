// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

// 示例 1：
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[2,1,4,3,5]

// 示例 2：
// 输入：head = [1,2,3,4,5], k = 3
// 输出：[3,2,1,4,5]


#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr) return nullptr;

    std::vector<ListNode *> nodes;
    ListNode *temp = head;
    while(temp != nullptr)
    {
        nodes.push_back(temp);
        temp = temp->next;
    }

    if(nodes.size() < k) return head;

    int count = 0;
    while((count + 1) * k <= nodes.size())
    {
        int left = count * k;
        int right = left + k - 1;

        while(left < right)
        {
            std::swap(nodes[left], nodes[right]);
            left++;
            right--;
        }
        count++;
    }

    for (int i = 0; i < nodes.size() - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[nodes.size() - 1]->next = nullptr;
    return nodes[0];
}