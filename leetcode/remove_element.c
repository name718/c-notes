#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：27
 * 题目：Remove Element
 * 地址：https://leetcode.com/problems/remove-element/
 */

/*
 * 题目：移除元素
 * 难度：简单
 * 练习点：数组、双指针、原地修改、返回新长度
 *
 * 题意（改写）：
 * 给你一个数组 nums 和一个值 val，
 * 请原地删除所有等于 val 的元素，并返回删除后数组的新长度。
 * 新长度范围内的元素顺序可以改变，超过新长度的内容不关心。
 *
 * 示例：
 * 输入：nums = [3,2,2,3], val = 3
 * 输出：2
 * 说明：前两个元素可以是 [2,2]
 */

int removeElement(int *nums, int numsSize, int val)
{
    (void)nums;
    (void)numsSize;
    (void)val;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

static void assert_prefix_equal(const int *actual, const int *expected, int size)
{
    for (int i = 0; i < size; i++) {
        assert(actual[i] == expected[i]);
    }
}

static void run_tests(void)
{
    {
        int nums[] = {3, 2, 2, 3};
        int expected[] = {2, 2};
        int len = removeElement(nums, 4, 3);

        assert(len == 2);
        assert_prefix_equal(nums, expected, len);
    }

    {
        int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
        int expected[] = {0, 1, 3, 0, 4};
        int len = removeElement(nums, 8, 2);

        assert(len == 5);
        assert_prefix_equal(nums, expected, len);
    }

    {
        int nums[] = {1, 1, 1};
        int len = removeElement(nums, 3, 1);

        assert(len == 0);
    }
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("remove_element.c: all tests passed\n");
    return 0;
}
#endif
