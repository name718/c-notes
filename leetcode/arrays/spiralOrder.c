#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 顺时针遍历
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int top = 0;                    // 上边界
    int bottom = matrixSize - 1;    // 下边界
    int left = 0;                   // 左边界
    int right = *matrixColSize - 1; // 右边界
    int total = matrixSize * (*matrixColSize);
    *returnSize = total;
    
    int* ans = (int*)malloc(sizeof(int) * total);
    int idx = 0;
    
    while (top <= bottom && left <= right) {
        // 1. 从左到右遍历上边
        for (int i = left; i <= right; i++) {
            ans[idx++] = matrix[top][i];
        }
        top++;
        
        // 2. 从上到下遍历右边
        for (int i = top; i <= bottom; i++) {
            ans[idx++] = matrix[i][right];
        }
        right--;
        
        // 3. 从右到左遍历下边（需要确保还有行）
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans[idx++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        // 4. 从下到上遍历左边（需要确保还有列）
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans[idx++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return ans;
}