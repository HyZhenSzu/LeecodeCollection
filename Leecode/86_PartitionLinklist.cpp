// 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置。

// 示例 1：
// 输入：head = [1,4,3,2,5,2], x = 3
// 输出：[1,2,2,4,3,5]

// 示例 2：
// 输入：head = [2,1], x = 2
// 输出：[1,2]

#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    if(head == nullptr)
        return head;
    ListNode *larger = new ListNode(0);
    ListNode *largerHead = larger;
    
    while(head != nullptr && head->val >= x)
    {
        std::cout << "Head's value is more than x\n"
                  << std::flush;
        ListNode *node = head;
        head = head->next;
        node->next = nullptr;
        larger->next = node;
        larger = larger->next;
    }

    ListNode *temp = head;
    while(temp != nullptr && temp->next != nullptr)
    {
        std::cout << "Next value is " << temp->next->val << std::endl;
        if(temp->next != nullptr && temp->next->val < x)
        {
            temp = temp->next;
            continue;
        }

        std::cout << "Now Temp's value is " << temp->val << std::endl;
        std::cout << "Next value is " << temp->next->val << std::endl;
        std::cout << "Move temp->next to larger\n"
                  << std::flush;
        ListNode *swapNode = temp->next;
        temp->next = temp->next->next;
        swapNode->next = nullptr;
        larger->next = swapNode;
        larger = larger->next;
        std::cout << "Now Temp is in " << temp->val << std::endl;
        std::cout << "Temp->next value is " << temp->next->val << std::endl;
    }
    if(temp == nullptr)
        return largerHead->next;
    temp->next = largerHead->next;
    return head;
}

int main()
{
    std::vector<int> vals = {1};
    int x = 0;
    ListNode* head = new ListNode(vals[0]);
    ListNode *p = head;
    for(int i = 1; i < vals.size(); i++)
    {
        ListNode *newNode = new ListNode(vals[i]);
        p->next = newNode;
        p = p->next;
    }
    head = partition(head, x);
    p = head;
    int times = 10;
    while(p != nullptr && times > 0)
    {
        std::cout << p->val << " ";
        p = p->next;
        times--;
    }
    std::cout << std::endl;
    return 0;
}