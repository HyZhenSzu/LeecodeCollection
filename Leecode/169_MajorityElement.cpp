// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

// 示例 1：
// 输入：nums = [3,2,3]
// 输出：3

// 示例 2：
// 输入：nums = [2,2,1,1,1,2,2]
// 输出：2
 
#include <iostream>
#include <vector>
#include <map>

int majorityElement(std::vector<int>& nums) {
    std::map<int, int> m_Value_to_Times;
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        // if(m_Value_to_Times.find(*it) != m_Value_to_Times.end())
        // {
        //     m_Value_to_Times[*it] = 1;
        // }
        m_Value_to_Times[*it] += 1;
    }

    for (std::map<int, int>::iterator it = m_Value_to_Times.begin(); it != m_Value_to_Times.end(); it++)
    {
        if(it->second > nums.size() / 2)
        {
            return it->first;
        }
    }
    return -1;
}