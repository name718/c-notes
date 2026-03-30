#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：1122
 * 题目：Relative Sort Array
 * 地址：https://leetcode.com/problems/relative-sort-array/
 */

/*
 * 题目：数组的相对排序
 * 难度：简单
 * 练习点：计数排序、哈希统计、自定义输出顺序
 *
 * 题意（改写）：
 * 给你两个数组 arr1 和 arr2，其中 arr2 中元素各不相同，
 * 且 arr2 中每个元素都出现在 arr1 中。请对 arr1 排序：
 * 先按 arr2 中顺序排列其包含的元素，其余元素按升序放在末尾。
 *
 * 算法描述：
 * 1. 统计 arr1 每个值的出现次数。
 * 2. 按 arr2 顺序写入对应数量的元素到结果。
 * 3. 将剩余未写入元素按升序补到末尾。
 */

int *relativeSortArray(int *arr1,
                       int arr1Size,
                       int *arr2,
                       int arr2Size,
                       int *returnSize)
{
    (void)arr1;
    (void)arr1Size;
    (void)arr2;
    (void)arr2Size;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("relative_sort_array.c template ready\n");
    return 0;
}
#endif
