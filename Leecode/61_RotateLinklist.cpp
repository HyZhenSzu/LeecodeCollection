// 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。


// 示例 1：
// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]

// 示例 2：
// 输入：head = [0,1,2], k = 4
// 输出：[2,0,1]

#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || k == 0) return nullptr;
    ListNode* temp = head;
    int length = 0;
    while(temp != nullptr)
    {
        length++;
        temp = temp->next;
    }

    if(length == 1 || k % length == 0) return head;
    int newHeadPos = length - k % length;
    temp = head;
    for(int i = 0; i < newHeadPos; i++)
    {
        temp = temp->next;
    }
    ListNode *newHead = temp;
    while(temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;
    temp = newHead;
    for(int i = 0; i < length - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
    return newHead;
}