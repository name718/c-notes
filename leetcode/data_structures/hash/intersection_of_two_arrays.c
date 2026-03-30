#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：349
 * 题目：Intersection of Two Arrays
 * 地址：https://leetcode.com/problems/intersection-of-two-arrays/
 */

/*
 * 题目：两个数组的交集
 * 难度：简单
 * 练习点：哈希集合、去重、数组结果构造
 *
 * 题意（改写）：
 * 给定两个数组，返回它们的交集。结果中的每个元素必须唯一，顺序不限。
 *
 * 算法描述：
 * 1. 先将一个数组放入哈希集合。
 * 2. 遍历另一个数组，若在集合中则加入结果集合。
 * 3. 最后将结果集合转为数组返回。
 */

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    (void)nums1;
    (void)nums1Size;
    (void)nums2;
    (void)nums2Size;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}
