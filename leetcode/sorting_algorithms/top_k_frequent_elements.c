#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：347
 * 题目：Top K Frequent Elements
 * 地址：https://leetcode.cn/problems/top-k-frequent-elements/
 */

/*
 * 题目：前 K 个高频元素
 * 难度：中等
 * 练习点：哈希计数、堆、桶排序
 *
 * 题意（改写）：
 * 给你一个整数数组 nums 和整数 k，返回其中出现频率前 k 高的元素。
 * 返回顺序不限。
 *
 * 算法描述：
 * 1. 先统计每个元素的出现频次。
 * 2. 使用最小堆维护前 k 个高频元素，或使用桶排序按频次分组。
 * 3. 最终导出 k 个结果并通过 returnSize 返回长度。
 */

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize)
{
    (void)nums;
    (void)numsSize;
    (void)k;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("top_k_frequent_elements.c template ready\n");
    return 0;
}
#endif
