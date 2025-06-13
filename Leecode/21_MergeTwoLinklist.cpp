// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


// 示例 1：
// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]

// 示例 2：
// 输入：l1 = [], l2 = []
// 输出：[]

// 示例 3：
// 输入：l1 = [], l2 = [0]
// 输出：[0]

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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

    ListNode* leftPtr = list1;
    ListNode *rightPtr = list2;
    ListNode *newList = new ListNode();
    ListNode *head = newList;
    while(leftPtr != nullptr && rightPtr != nullptr)
    {
        if(leftPtr->val <= rightPtr->val)
        {
            ListNode *newNode = new ListNode(leftPtr->val);
            newList->next = newNode;
            newList = newList->next;
            leftPtr = leftPtr->next;
        }
        else
        {
            ListNode* newNode = new ListNode(rightPtr->val);
            newList->next = newNode;
            newList = newList->next;
            rightPtr = rightPtr->next;
        }
    }
    while(leftPtr != nullptr)
    {
        ListNode* newNode = new ListNode(leftPtr->val);
        newList->next = newNode;
        newList = newList->next;
        leftPtr = leftPtr->next;
    }
    while(rightPtr != nullptr)
    {
        ListNode* newNode = new ListNode(rightPtr->val);
        newList->next = newNode;
        newList = newList->next;
        rightPtr = rightPtr->next;
    }
    return head->next;
}
