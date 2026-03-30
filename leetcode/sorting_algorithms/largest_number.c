#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：179
 * 题目：Largest Number
 * 地址：https://leetcode.cn/problems/largest-number/
 */

/*
 * 题目：最大数
 * 难度：中等
 * 练习点：自定义排序、字符串比较、边界处理
 *
 * 题意（改写）：
 * 给定一组非负整数 nums，重新排列它们的顺序，
 * 使其拼接成的整数最大，并以字符串形式返回结果。
 *
 * 算法描述：
 * 1. 将整数转为字符串。
 * 2. 自定义排序规则：比较 a+b 与 b+a 的字典序决定先后。
 * 3. 排序后拼接；若最高位为 "0"，直接返回 "0"。
 */

char *largestNumber(int *nums, int numsSize)
{
    (void)nums;
    (void)numsSize;

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("largest_number.c template ready\n");
    return 0;
}
#endif
