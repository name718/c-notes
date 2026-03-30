#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：56
 * 题目：Merge Intervals
 * 地址：https://leetcode.cn/problems/merge-intervals/
 */

/*
 * 题目：合并区间
 * 难度：中等
 * 练习点：排序、区间处理、二维数组返回
 *
 * 题意（改写）：
 * 以二维数组 intervals 表示若干区间 [start, end]，
 * 合并所有重叠区间并返回不重叠区间数组。
 *
 * 算法描述：
 * 1. 先按区间起点升序排序。
 * 2. 依次扫描区间，与当前合并区间比较是否重叠。
 * 3. 重叠则更新右边界，不重叠则写入结果并开始新区间。
 */

int **merge(int **intervals,
            int intervalsSize,
            int *intervalsColSize,
            int *returnSize,
            int **returnColumnSizes)
{
    (void)intervals;
    (void)intervalsSize;
    (void)intervalsColSize;

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
    printf("merge_intervals.c template ready\n");
    return 0;
}
#endif
