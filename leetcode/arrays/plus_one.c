#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：66
 * 题目：Plus One
 * 地址：https://leetcode.cn/problems/plus-one/
 */

/*
 * 题目：加一
 * 难度：简单
 * 练习点：数组、进位、动态内存、返回数组
 *
 * 题意（改写）：
 * 给你一个由十进制数字组成的数组 digits，
 * 数组整体表示一个非负整数，请在这个整数基础上加一。
 * 返回结果数组，并通过 returnSize 告诉调用者长度。
 *
 * 示例：
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 */

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    (void)digits;
    (void)digitsSize;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    *returnSize = digitsSize; // 默认返回原数组长度
    int carry = 1;

    for(int i = digitsSize - 1; i > -1; i --) {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        *returnSize += 1;
        int* res = (int*)malloc(*returnSize * sizeof(int));
        res[0] = 1;
        for (int i = 1; i < *returnSize; i ++) {
            res[i] = 0;
        }
        return res;
    }

    int* res = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i ++) {
            res[i] = digits[i];
    }
    return res;
}

static void assert_array_equal(const int *actual, const int *expected, int size)
{
    for (int i = 0; i < size; i++) {
        assert(actual[i] == expected[i]);
    }
}

static void run_tests(void)
{
    {
        int digits[] = {1, 2, 3};
        int expected[] = {1, 2, 4};
        int returnSize = 0;
        int *answer = plusOne(digits, 3, &returnSize);

        assert(returnSize == 3);
        assert_array_equal(answer, expected, 3);
        free(answer);
    }

    {
        int digits[] = {4, 3, 2, 1};
        int expected[] = {4, 3, 2, 2};
        int returnSize = 0;
        int *answer = plusOne(digits, 4, &returnSize);

        assert(returnSize == 4);
        assert_array_equal(answer, expected, 4);
        free(answer);
    }

    {
        int digits[] = {9};
        int expected[] = {1, 0};
        int returnSize = 0;
        int *answer = plusOne(digits, 1, &returnSize);

        assert(returnSize == 2);
        assert_array_equal(answer, expected, 2);
        free(answer);
    }
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("plus_one.c: all tests passed\n");
    return 0;
}
#endif
