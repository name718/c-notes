#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：136
 * 题目：Single Number
 * 地址：https://leetcode.cn/problems/single-number/
 */

/*
 * 题目：只出现一次的数字
 * 难度：简单
 * 练习点：数组、异或运算、位运算基础
 *
 * 题意（改写）：
 * 给你一个非空整数数组，除了某个元素只出现一次以外，
 * 其余每个元素都恰好出现两次。请找出那个只出现一次的元素。
 *
 * 示例：
 * 输入：[2,2,1]
 * 输出：1
 */

 int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
 }

int singleNumber(int *nums, int numsSize)
{
    (void)nums;
    (void)numsSize;

    /* TODO: 在这里完成具体实现 */
    // 先排序
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result;
}

static void run_tests(void)
{
    {
        int nums[] = {2, 2, 1};
        assert(singleNumber(nums, 3) == 1);
    }

    {
        int nums[] = {4, 1, 2, 1, 2};
        assert(singleNumber(nums, 5) == 4);
    }

    {
        int nums[] = {1};
        assert(singleNumber(nums, 1) == 1);
    }
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("single_number.c: all tests passed\n");
    return 0;
}
#endif
