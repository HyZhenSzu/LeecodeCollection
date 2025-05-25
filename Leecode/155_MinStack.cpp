// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

// 实现 MinStack 类:

// MinStack() 初始化堆栈对象。
// void push(int val) 将元素val推入堆栈。
// void pop() 删除堆栈顶部的元素。
// int top() 获取堆栈顶部的元素。
// int getMin() 获取堆栈中的最小元素。
 

// 示例 1:
// 输入：
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// 输出：
// [null,null,null,null,-3,null,0,-2]

// 解释：
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.

#include <iostream>
#include <algorithm>

class MinStack {
public:
    MinStack() {
        m_maxSize = 100;
        m_stack = new int[m_maxSize];
        m_length = 0;
        m_minElement = INT_MAX;
    }
    
    void push(int val) {
        if(m_length == m_maxSize)
        {
            m_maxSize *= 2;
            int *temp = new int[m_maxSize];
            for (int i = 0; i < m_length; i++)
            {
                temp[i] = m_stack[i];
            }
            delete[] m_stack;
            m_stack = temp;
        }
        m_stack[m_length++] = val;
        if(val < m_minElement)
            m_minElement = val;
    }
    
    void pop() {
        m_length--;
        std::cout << "New length: " << m_length << std::endl;
        if(m_length >= 1 && m_minElement == m_stack[m_length])
        {
            auto it = std::min_element(m_stack, m_stack + m_length);
            m_minElement = *it;
        }
        if(m_length == 0)
            m_minElement = INT_MAX;
    }
    
    int top() {
        return m_stack[m_length - 1];
    }
    
    int getMin() {
        return m_minElement;
    }

private:
    int *m_stack;
    int m_length;
    int m_maxSize;
    int m_minElement;
};

// int main()
// {
//     MinStack* minStack = new MinStack();
//     minStack->push(2);
//     minStack->push(0);
//     minStack->push(3);
//     minStack->push(0);
//     std::cout << minStack->getMin() << std::endl;
//     for (int i = 0; i < 3; i++)
//     {
//         minStack->pop();
//         std::cout << minStack->getMin() << std::endl;
//     }
//     return 0;
// }