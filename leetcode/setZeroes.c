// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

#define TRUE 1
#define FALSE 0

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    // 1、判断第一列，第一行是否有 0
    // 2、循环内部矩阵，判断是不是 0，如果是 0 则设置对应的0 列和 1 行为 0
    // 3、在循环一次，如狗 （0，i）或者（j，0）是 0 则内部矩阵（i，j）就是 0

    int row_0_has_zero = FALSE;
    int col_0_has_zero = FALSE;
    // 判断第一列是否有 0
    for (int i = 0; i < matrixSize; i ++) {
        if (matrix[i][0] == 0) {
            col_0_has_zero = TRUE;
            break;
        }
    }
    // 判断第一行是否有 0
    for (int i = 0; i < *matrixColSize; i ++) {
        if (matrix[0][i] == 0) {
            row_0_has_zero = TRUE;
            break;
        }
    }

    // 内层循环
    for(int i = 1; i < matrixSize; i ++) {
        for (int j = 1; j < *matrixColSize; j ++) {
            if (matrix[i][j] == 0) {
                // 将第一行，第一列设置为 0
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // 根据第一行和第一列的标记，将内部矩阵置零
    for (int i = 1; i < matrixSize; i ++) {
        for (int j = 1; j < *matrixColSize; j ++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // 秋后算账，
    if(row_0_has_zero) {
        for (int i = 0; i < *matrixColSize; i ++) {
            matrix[0][i] = 0;
        }
    }

    if (col_0_has_zero) {
        for (int i = 0; i < matrixSize; i ++) {
            matrix[i][0] = 0;
        }
    }
}