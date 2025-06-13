// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

// 示例 1：
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]

// 示例 2：
// 输入：head = [1], n = 1
// 输出：[]

// 示例 3：
// 输入：head = [1,2], n = 1
// 输出：[1]

#include <vector>
#include <iostream>

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *temp = head;
    int length = 0;
    while(temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    temp = head;
    int pos = length - n;
    // std::cout << "length is: " << length << " pos is: " << pos << std::endl;
    if(pos == 0)
        return head->next;
    while(pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    // std::cout << "Now temp is " << temp->val << std::endl;
    temp->next = temp->next->next;
    return head;
}

// int main()
// {
//     ListNode *head = new ListNode(1);
//     ListNode *p = head;
//     ListNode *newNode = new ListNode(2);
//     p->next = newNode;
//     // int length = 1;
//     // while(length < 5)
//     // {
//     //     length++;
//     //     ListNode *newNode = new ListNode(length);
//     //     p->next = newNode;
//     //     p = p->next;
//     // }
//     removeNthFromEnd(head, 1);
//     return 0;
// }
