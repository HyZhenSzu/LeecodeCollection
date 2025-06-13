// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

// 示例 1：
// 输入：head = [1,2,3,3,4,4,5]
// 输出：[1,2,5]

// 示例 2：
// 输入：head = [1,1,1,2,3]
// 输出：[2,3]

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


ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr)
        return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next;
        std::cout << "fast : " << fast->val << " slow is " << slow->val << std::endl;
        if(fast != nullptr && slow != nullptr && fast->val != slow->val)
        {
            slow = slow->next;
            continue;
        }

        while(fast != nullptr && slow != nullptr && fast->val == slow->val)
        {
            fast = fast->next;
        }

        std::cout << "Find duplicate node val is " << slow->val << std::endl;
        if(slow == head)
        {
            head = fast;
            slow = fast;
            if(head == nullptr)
                return nullptr;
            continue;
        }

        ListNode* temp = head;
        while(temp->next != slow)
        {
            temp = temp->next;
        }
        std::cout << "Find temp node val is " << temp->val << std::endl;
        temp->next = fast;
        slow = fast;
    }
    return head;
}

int main()
{
    std::vector<int> vals = {1,1,2,2};
    ListNode *head = new ListNode(vals[0]);
    ListNode *temp = head;
    for(int i = 1; i < vals.size(); i++)
    {
        ListNode* newNode = new ListNode(vals[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    ListNode * p = deleteDuplicates(head);
    while(p != nullptr)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
    return 0;
}