// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。


// 示例 1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[7,4,1],[8,5,2],[9,6,3]]

// 示例 2：
// 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix) {
    int len = matrix.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len / 2; j++)
        {
            std::swap(matrix[i][j], matrix[i][len - j - 1]);
        }
    }
}

// int main()
// {
//     std::vector<std::vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
//     rotate(matrix);
//     for(int i = 0; i < matrix.size(); i++)
//     {
//         for(int j = 0; j < matrix.size(); j++)
//         {
//             std::cout << matrix[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     return 0;
// }