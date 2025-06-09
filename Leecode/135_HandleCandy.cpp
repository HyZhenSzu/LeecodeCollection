// n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

// 你需要按照以下要求，给这些孩子分发糖果：

// 每个孩子至少分配到 1 个糖果。
// 相邻两个孩子评分更高的孩子会获得更多的糖果。
// 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

// 示例 1：
// 输入：ratings = [1,0,2]
// 输出：5
// 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。

// 示例 2：
// 输入：ratings = [1,2,2]
// 输出：4
// 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
//      第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

#include <iostream>
#include <vector>

int candy(std::vector<int>& ratings)
{
    std::vector<int> left(ratings.size(), 1);
    std::vector<int> right(ratings.size(), 1);
    for(int i = 1; i < ratings.size(); i++)
    {
        if(ratings[i - 1] < ratings[i])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    for(int i = ratings.size() - 2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }

    int numOfCandy = 0;
    for(int i = 0; i < ratings.size(); i++)
    {
        numOfCandy += std::max(left[i], right[i]);
    }
    return numOfCandy;
}