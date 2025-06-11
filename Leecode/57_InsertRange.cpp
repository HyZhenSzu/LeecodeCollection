// 给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
// 在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
// 返回插入之后的 intervals。

// 注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。

// 示例 1：
// 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
// 输出：[[1,5],[6,9]]

// 示例 2
// 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// 输出：[[1,2],[3,10],[12,16]]
// 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。


#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    if(intervals.size() == 0) return {newInterval};
    std::vector<std::vector<int>> result;
    int i;
    for(i = 0; i < intervals.size(); i++)
    {
        if(intervals[i][0] <= newInterval[0])
        {
            result.push_back(intervals[i]);
            continue;
        }
        break;
    }
    if(result.size() > 0 && newInterval[0] <= result[result.size() - 1][1])
    {
        // 重叠区间
        result[result.size() - 1][1] = std::max(result[result.size() - 1][1], newInterval[1]);
    }
    else
        result.push_back(newInterval);

    for(; i < intervals.size(); i++)
    {
        if(intervals[i][0] <= result[result.size() - 1][1])
        {
            result[result.size() - 1][1] = std::max(result[result.size() - 1][1], intervals[i][1]);
            continue;
        }
        result.push_back(intervals[i]);
    }
    return result;
}