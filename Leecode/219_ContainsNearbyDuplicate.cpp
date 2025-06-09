// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
// 满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

// 示例 1：
// 输入：nums = [1,2,3,1], k = 3
// 输出：true

// 示例 2：
// 输入：nums = [1,0,1,1], k = 1
// 输出：true

// 示例 3：
// 输入：nums = [1,2,3,1,2,3], k = 2
// 输出：false

#include <iostream>
#include <vector>
#include <unordered_map>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    if(nums.size() < k) return false;
    std::unordered_map<int, int> checkList;
    for(int i = 0; i < nums.size(); i++)
    {
        if(checkList.find(nums[i]) == checkList.end())
            checkList[nums[i]] = i;
        else
            return true;

        if(checkList.size() == k + 1)
            checkList.erase(nums[i - k]);
    }
    return false;
}

// int main()
// {
//     std::vector<int> nums = {1,2,3,1,2,3};
//     containsNearbyDuplicate(nums, 2);
//     return 0;
// }