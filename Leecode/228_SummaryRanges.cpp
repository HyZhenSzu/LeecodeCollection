// 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。
// 列表中的每个区间范围 [a,b] 应该按如下格式输出：

// "a->b" ，如果 a != b
// "a" ，如果 a == b
 
// 示例 1：
// 输入：nums = [0,1,2,4,5,7]
// 输出：["0->2","4->5","7"]
// 解释：区间范围是：
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"

// 示例 2：
// 输入：nums = [0,2,3,4,6,8,9]
// 输出：["0","2->4","6","8->9"]
// 解释：区间范围是：
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    if(nums.size() == 0) return {};
    std::vector<std::string> result;
    int max = nums[0];
    int min = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i] <= nums[i - 1] + 1)
        {
            max = nums[i];
            continue;
        }
        if(min == max)
            result.push_back(std::to_string(min));
        else
            result.push_back(std::to_string(min) + "->" + std::to_string(max));
        min = nums[i];
        max = nums[i];
    }
    if(min == max)
        result.push_back(std::to_string(min));
    else
        result.push_back(std::to_string(min) + "->" + std::to_string(max));
    return result;
}