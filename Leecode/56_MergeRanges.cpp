// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
// 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

// 示例 1：
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

// 示例 2：
// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if(intervals.size() == 0) return {};

    std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &a, std::vector<int> &b){
        return a[0] < b[0]; 
    });
    std::vector<std::vector<int>>result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        int begin = result.back()[0];
        int end = result.back()[1];
        if(end < intervals[i][0])
        {
            result.push_back(intervals[i]);
            continue;
        }
        begin = std::min(begin, intervals[i][0]);
        end = std::max(end, intervals[i][1]);
        result.back()[0] = begin;
        result.back()[1] = end;
    }
    return result;
}

// int main()
// {
//     std::vector<std::vector<int>> intervals = {{2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}};
//     auto res = merge(intervals);
//     for(auto row = res.begin(); row != res.end(); row++)
//     {
//         for(auto it = row->begin(); it != row->end(); it++)
//             std::cout << *it << " ";
//         std::cout << "\n";
//     }
//     return 0;
// }