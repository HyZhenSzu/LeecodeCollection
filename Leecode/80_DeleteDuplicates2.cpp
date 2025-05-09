// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 

// 说明：
// 为什么返回数值是整数，但输出的答案是数组呢？
// 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
// 你可以想象内部操作如下:

// // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
// int len = removeDuplicates(nums);

// // 在函数里修改输入数组对于调用者是可见的。
// // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }
 
// 示例 1：
// 输入：nums = [1,1,1,2,2,3]
// 输出：5, nums = [1,1,2,2,3]
// 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。

// 示例 2：
// 输入：nums = [0,0,1,1,1,1,2,3,3]
// 输出：7, nums = [0,0,1,1,2,3,3]
// 解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。

#include <iostream>
#include <vector>

// 方法一：（时间复杂度太高了）
// int removeDuplicates(std::vector<int>& nums) {
//     int count = 0;
//     int len = nums.size();
//     for (int i = 0; i < len; i++)
//     {
//         count = 1;
//         std::cout << "start from i = " << i << " nums[i] = " << nums[i] << std::endl;
//         // std::cout << "val i is: " << i << " nums[i] is: " << nums[i] << std::endl;
//         while(i < len - 1 && nums[i] == nums[i + 1]) 
//         {
//             std::cout << "In loop 1: " << std::endl;
//             std::cout << "val i is: " << i <<  " nums[i] is: " << nums[i] << " count is: " << count << "\n\n";

//             count++;
//             i++;
//         }
//         std::cout << "len is: " << len << " val i is: " << i << " nums[i] is: " << nums[i] << " count is: " << count << "" << "\nFinish a element\n";
//         if(count > 2)
//         {
//             int step = count - 2;
//             len -= step;
//             for (int j = i - step + 1; j < len; j++)
//             {
//                 nums[j] = nums[j + step];
//             }
//             i -= step;
//         }
//         for (int i = 0; i < len; i++) {
//             std::cout << nums[i];
//         }
//         std::cout << std::endl;
//     }
//     return len;
// }



// 方法二：(两者相对平衡，但是)
int removeDuplicates(std::vector<int>& nums) {
    int len = nums.size();
    if(len <= 2)
        return len;

    int slow = 2;
    int fast = 2;

    while(fast < len)
    {
        if(nums[slow - 2] != nums[fast])
        {
            nums[slow++] = nums[fast];
        }
        fast++;
    }
    return slow;
}

// 检查：
// int main()
// {
//     std::vector<int>nums = {0,0,1,1,1,1,2,2,2,4};
//     int len = removeDuplicates(nums);
//     for (int i = 0; i < len; i++) {
//         std::cout << nums[i];
//     }
// }