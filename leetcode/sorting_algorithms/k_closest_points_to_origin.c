#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：973
 * 题目：K Closest Points to Origin
 * 地址：https://leetcode.com/problems/k-closest-points-to-origin/
 */

/*
 * 题目：最接近原点的 K 个点
 * 难度：中等
 * 练习点：堆、快速选择、二维数组处理
 *
 * 题意（改写）：
 * 给定二维平面上的点 points[i] = [xi, yi] 和整数 k，
 * 返回距离原点 (0, 0) 最近的 k 个点，顺序不限。
 *
 * 算法描述：
 * 1. 以平方距离 x*x + y*y 作为比较依据。
 * 2. 可用大小为 k 的最大堆维护当前最近 k 个点。
 * 3. 或用快速选择把前 k 个位置划分为最近点集合。
 */

int **kClosest(int **points,
               int pointsSize,
               int *pointsColSize,
               int k,
               int *returnSize,
               int **returnColumnSizes)
{
    (void)points;
    (void)pointsSize;
    (void)pointsColSize;
    (void)k;

    if (returnSize != NULL) {
        *returnSize = 0;
    }
    if (returnColumnSizes != NULL) {
        *returnColumnSizes = NULL;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("k_closest_points_to_origin.c template ready\n");
    return 0;
}
#endif
