#include <stdbool.h>
// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = 0;
    // 初始位置：将指针放在矩阵的右上角元素 matrix[0][n-1]。
    int col = *matrixColSize - 1;

    while (row < matrixSize && col >= 0)
    {
        int currentN = matrix[row][col];
        // 如果当前元素 等于 target，直接成功找到，返回 true。
        if (currentN == target) {
            return true;
        }
        // 如果当前元素 大于 target：说明当前所在的这一整列都肯定大于 target（因为越往下越大）
        // 所以这列下面的数据不用看了，直接向左移动一格，剔除这一列。
        if (currentN > target) {
            col -= 1;
        }
        // 如果当前元素 小于 target：说明当前所在的这一整行都肯定小于 target（因为左边的只可能更小）
        // 所以这行左边的数据不用看了，直接向下移动一格，剔除这一行。
        if (currentN < target) {
            row += 1;
        }
    }
    
    return false;
}