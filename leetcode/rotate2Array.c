// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

/**
 * 顺时针旋转 n x n 矩阵 90 度（原地旋转）
 * 思路：先上下翻转，再沿主对角线翻转（转置）
 */
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    
    // 1. 上下翻转：交换第 i 行和第 n-1-i 行
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - i][j];
            matrix[n - 1 - i][j] = temp;
        }
    }
    
    // 2. 沿主对角线翻转（转置）：交换 matrix[i][j] 和 matrix[j][i]
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}