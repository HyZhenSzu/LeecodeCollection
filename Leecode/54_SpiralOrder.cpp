// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

// 示例1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]

// 示例2：
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    enum Direction
    {
        Right = 0,
        Down,
        Left,
        Up,
        DIRECTION_COUNT
    };
    std::vector<int> result;
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;
    int direction = Direction::Right;
    int i = top;
    int j = left;
    while(left <= right && top <= bottom)
    {
        switch(direction)
        {
        case Right:
            while(j < right)
            {
                result.push_back(matrix[i][j]);
                j++;
            }
            top++;
            direction = Direction::Down;
            break;
        case Down:
            while(i < bottom)
            {
                result.push_back(matrix[i][j]);
                i++;
            }
            right--;
            direction = Direction::Left;
            break;
        case Left:
            while(j > left)
            {
                result.push_back(matrix[i][j]);
                j--;
            }
            bottom--;
            direction = Direction::Up;
            break;
        case Up:
            while(i > top)
            {
                result.push_back(matrix[i][j]);
                i--;
            }
            left++;
            direction = Direction::Right;
            break;
        default:
            break;
        }
    }
    result.push_back(matrix[i][j]);
    // for (auto it = result.begin(); it != result.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << "\n"
    //           << std::flush;
    return result;
}

// int main()
// {
//     std::vector<std::vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     spiralOrder(matrix); 
//     return 0;
// }