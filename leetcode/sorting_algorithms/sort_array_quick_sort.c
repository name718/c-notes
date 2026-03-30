#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：912
 * 题目：Sort an Array
 * 地址：https://leetcode.cn/problems/sort-an-array/
 */

/*
 * 题目：排序数组（快速排序版）
 * 难度：中等
 * 练习点：分治、快速排序、原地交换、递归边界
 *
 * 题意（改写）：
 * 给你一个整数数组 nums，请你将该数组升序排列后返回。
 *
 * 算法描述（快速排序）：
 * 1. 选择基准元素（pivot），将数组分成小于等于 pivot 与大于 pivot 的两部分。
 * 2. 对左右分区递归执行相同过程。
 * 3. 当分区长度为 0 或 1 时停止递归。
 */

int *sortArray(int *nums, int numsSize, int *returnSize)
{
    (void)nums;
    (void)numsSize;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("sort_array_quick_sort.c template ready\n");
    return 0;
}
#endif
