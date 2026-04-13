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

static int cmp(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    return intervalA[0] - intervalB[0];
}
/**
 * @brief 合并所有重叠的区间
 *
 * @param intervals 输入的二维区间数组，每个元素是一个 [start, end] 区间
 * @param intervalsSize 区间的总个数
 * @param intervalsColSize 每个区间的列数（固定为 2）
 * @param returnSize 输出参数：返回结果的区间个数
 * @param returnColumnSizes 输出参数：返回结果中每个区间的列数数组
 * @return int** 合并后的新区间数组，需要手动释放内存
 *
 * @note 必须按左端点排序后再合并
 * @warning 返回的内存需要调用方手动 free 释放
 */
int **merge(int **intervals,
            int intervalsSize,
            int *intervalsColSize,
            int *returnSize,
            int **returnColumnSizes)
{
    // 处理空数组的情况
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    // 1、先根据 start 非降序排序
    qsort(intervals,intervalsSize, sizeof(int*),cmp);
    // 2、申请结果数组空间
    int **res = (int **)malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * intervalsSize);

    int count = 0;
    res[count] = (int *)malloc(sizeof(int) * 2);
    res[count][0] = intervals[0][0];
    res[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count ++;
    // 2、循环取出returnColumnSizes的最后一个区间和当前区间进行判断是否有重复。
    for (int i = 1; i < intervalsSize; i ++) {
        int currentStart = intervals[i][0];
        int currentEnd = intervals[i][1];
        int lastStart = res[count - 1][0];
        int lastEnd = res[count - 1][1];

        if (lastEnd >= currentStart) {
            // 有重合
            res[count - 1][1] = currentEnd > lastEnd ? currentEnd : lastEnd;
        } else {
            // 没有重合则 push res 中
            res[count] = (int *)malloc(sizeof(int) * 2);
            res[count][0] = currentStart;
            res[count][1] = currentEnd;
            (*returnColumnSizes)[count] = 2;
            count ++;
        }
    }

    *returnSize = count;
    return res;
}


// ==================== 测试代码 ====================
#ifndef LEETCODE_SUBMISSION
int main(void)
{
    // 测试用例 1
    int interval1[] = {1, 3};
    int interval2[] = {2, 6};
    int interval3[] = {8, 10};
    int interval4[] = {15, 18};

    int *intervals[] = {interval1, interval2, interval3, interval4};
    int intervalsSize = 4;
    int intervalsColSize = 2;

    int returnSize;
    int *returnColumnSizes;

    int **res = merge(intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes);

    printf("合并结果：\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", res[i][0], res[i][1]);
        free(res[i]);
    }

    free(res);
    free(returnColumnSizes);

    return 0;
}
#endif