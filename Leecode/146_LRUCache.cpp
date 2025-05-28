// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
// 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


// 示例：

// 输入
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// 输出
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// 解释
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // 缓存是 {1=1}
// lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
// lRUCache.get(1);    // 返回 1
// lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
// lRUCache.get(2);    // 返回 -1 (未找到)
// lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
// lRUCache.get(1);    // 返回 -1 (未找到)
// lRUCache.get(3);    // 返回 3
// lRUCache.get(4);    // 返回 4

#include <iostream>
#include <unordered_map>

struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) 
    {
        std::cout << "Create new node [" << key << ", " << val << "]" << std::endl;
    }
};

class LRUCache {
public:
    LRUCache(int capacity): m_capacity(capacity), m_currentSize(0), m_head(nullptr), m_tail(nullptr) 
    {
        std::cout << "Create a LRUCache with capacity " << capacity << std::endl;
    }
    
    int get(int key) {
        if(m_currentSize == 0)
            return -1;
        if(m_cacheContent.find(key) == m_cacheContent.end())
            return -1;

        visitNode(m_cacheContent[key]);
        return m_tail->val;
    }
    
    void put(int key, int value) {
        if(m_cacheContent.find(key) != m_cacheContent.end())
        {
            m_cacheContent[key]->val = value;
            visitNode(m_cacheContent[key]);
            return;
        }

        if(m_currentSize == m_capacity)
        {
            std::cout << "Delete Node [" << m_head->key << ", " << m_head->val << "]" << std::endl;
            m_cacheContent.erase(m_head->key);
            m_head = m_head->next;
            if(m_head != nullptr)
                m_head->prev = nullptr;
            m_currentSize--;
        }
        
        Node* newNode = new Node(key, value);
        m_cacheContent[key] = newNode;
        if(m_currentSize == 0)
        {
            m_head = newNode;
            m_tail = newNode;
            m_currentSize++;
            return;
        }
        newNode->prev = m_tail;
        m_tail->next = newNode;
        m_tail = m_tail->next;
        m_currentSize++;
        std::cout << "Add Node [" << m_tail->key << ", " << m_tail->val << "]" << std::endl;
    }

    bool visitNode(Node* p)
    {
        if(p == nullptr)
            return false;

        std::cout << "Visit Node [" << p->key << ", " << p->val << "]" << std::endl;
        
        if(p == m_tail)
            return true;
        
        if(p == m_head)
        {
            m_head = m_head->next;
            m_head->prev = nullptr;
        }

        if(p->prev != nullptr)
        {
            p->prev->next = p->next;    
        }
        p->next->prev = p->prev;
        p->prev = m_tail;
        m_tail->next = p;
        m_tail = m_tail->next;
        m_tail->next = nullptr;
        return true;
    }

    void printCache()
    {
        Node *p = m_head;
        while(p != nullptr)
        {
            std::cout << p->key << " " << p->val << std::endl;
            p = p->next;
        }
    }

private:
    std::unordered_map<int, Node*> m_cacheContent;
    Node *m_head;
    Node *m_tail;
    int m_capacity;
    int m_currentSize;
};

// int main()
// {
//     // ["LRUCache","put","get","put","get","get"]
//     // [[1],[2,1],[2],[3,2],[2],[3]]
//     LRUCache lRUCache(1);
//     lRUCache.put(2, 1);
//     lRUCache.printCache();
//     std::cout << lRUCache.get(2) << std::endl;
//     lRUCache.printCache();
//     lRUCache.put(3, 2);
//     lRUCache.printCache();
//     std::cout << lRUCache.get(2) << std::endl;
//     lRUCache.printCache();
//     std::cout << lRUCache.get(3) << std::endl;
//     lRUCache.printCache();
//     return 0;
// }

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */