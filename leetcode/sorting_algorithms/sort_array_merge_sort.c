#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：912
 * 题目：Sort an Array
 * 地址：https://leetcode.cn/problems/sort-an-array/
 */

/*
 * 题目：排序数组（归并排序版）
 * 难度：中等
 * 练习点：分治、归并排序、辅助数组、稳定排序
 *
 * 题意（改写）：
 * 给你一个整数数组 nums，请你将该数组升序排列后返回。
 *
 * 算法描述（归并排序）：
 * 1. 将数组不断二分，直到子数组长度为 1。
 * 2. 合并两个有序子数组，得到更大的有序数组。
 * 3. 逐层向上合并，最终得到整体有序结果。
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
    printf("sort_array_merge_sort.c template ready\n");
    return 0;
}
#endif
