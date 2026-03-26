#include <assert.h>
#include <stdio.h>

/*
 * 题目：x 的平方根
 * 难度：简单
 * 练习点：整数、二分查找、边界处理、防止溢出
 *
 * 题意（改写）：
 * 给你一个非负整数 x，计算并返回 x 的平方根的整数部分。
 * 返回值只保留整数部分，小数部分直接舍去。
 *
 * 示例：
 * 输入：x = 8
 * 输出：2
 */

int mySqrt(int x)
{
    (void)x;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

static void run_tests(void)
{
    assert(mySqrt(0) == 0);
    assert(mySqrt(1) == 1);
    assert(mySqrt(4) == 2);
    assert(mySqrt(8) == 2);
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("sqrt_x.c: all tests passed\n");
    return 0;
}
#endif
