// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

// 示例 1:
// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]

// 示例 2:
// 输入: nums = [-1,1,0,-3,3]
// 输出: [0,0,9,0,0]

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> LeftPro = {1};
    std::vector<int> RightPro = {1};
    int LeftPtr = 0;
    int RightPtr = nums.size() - 1;

    while(LeftPtr < nums.size() - 1 && RightPtr > 0)
    {
        LeftPro.push_back(LeftPro[LeftPro.size() - 1] * nums[LeftPtr]);
        LeftPtr++;
        RightPro.push_back(RightPro[RightPro.size() - 1] * nums[RightPtr]);
        RightPtr++;
    }

    // for (auto it = LeftPro.begin(); it != LeftPro.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << "\n";
    // for (auto it = RightPro.begin(); it != RightPro.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << "\n";

    std::vector<int> answer;
    auto itLeft = LeftPro.begin(); 
    auto itRight = RightPro.rbegin();

    while(itLeft != LeftPro.end() && itRight != RightPro.rend())
    {
        answer.push_back((*itLeft) * (*itRight));
        itLeft++;
        itRight--;
    }

    return answer;
}

// int main()
// {
//     std::vector<int> nums = {1, 2, 3, 4};
//     productExceptSelf(nums);
//     return 0;
// }