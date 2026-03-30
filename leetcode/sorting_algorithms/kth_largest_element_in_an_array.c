#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：215
 * 题目：Kth Largest Element in an Array
 * 地址：https://leetcode.com/problems/kth-largest-element-in-an-array/
 */

/*
 * 题目：数组中的第 K 个最大元素
 * 难度：中等
 * 练习点：快速选择、堆、分区思想
 *
 * 题意（改写）：
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 注意：这里找的是排序后第 k 大，不是第 k 个不同元素。
 *
 * 算法描述：
 * 1. 快速选择：每次分区后只递归目标区间，平均 O(n)。
 * 2. 或最小堆：维护大小为 k 的最小堆，遍历结束堆顶即答案。
 * 3. 处理边界：k 的取值满足 1 <= k <= numsSize。
 */

int findKthLargest(int *nums, int numsSize, int k)
{
    (void)nums;
    (void)numsSize;
    (void)k;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("kth_largest_element_in_an_array.c template ready\n");
    return 0;
}
#endif
