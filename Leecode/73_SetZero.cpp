// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

// 示例 1：
// 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：[[1,0,1],[0,0,0],[1,0,1]]

// 示例 2：
// 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int colLength = matrix.size();
    int rowLength = matrix[0].size();

    std::vector<bool> rowFlags(rowLength, false);
    std::vector<bool> colFlags(colLength, false);

    for(int i = 0; i < colLength; i++)
    {
        for(int j = 0; j < rowLength; j++)
        {
            if(matrix[i][j] == 0)
            {
                colFlags[i] = true;
                rowFlags[j] = true;
            }
        }
    }
    
    for(int i = 0; i < colLength; i++)
    {
        if(colFlags[i])
        {
            for(auto it = matrix[i].begin(); it != matrix[i].end(); it++)
                *it = 0;
        }
    }
    for (int i = 0; i < rowLength; i++)
    {
        if(rowFlags[i])
        {
            for(int j = 0; j < colLength; j++)
                matrix[j][i] = 0;
        }
    }
}

// int main()
// {
//     std::vector<std::vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
//     setZeroes(matrix);
//     return 0;
// }