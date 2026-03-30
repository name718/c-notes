#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：26
 * 题目：Remove Duplicates from Sorted Array
 * 地址：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
 */

/*
 * 题目：删除有序数组中的重复项
 * 难度：简单
 * 练习点：有序数组、双指针、原地修改、返回新长度
 *
 * 题意（改写）：
 * 给你一个非递减排序的数组 nums，
 * 请原地删除重复元素，使每个元素只出现一次，
 * 并返回删除后数组的新长度。
 *
 * 新长度范围内的元素需要保持原有相对顺序。
 *
 * 示例：
 * 输入：nums = [1,1,2]
 * 输出：2，前两个元素变为 [1,2]
 */

int removeDuplicates(int *nums, int numsSize)
{
    (void)nums;
    (void)numsSize;

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
        int nums[] = {1, 1, 2};
        int expected[] = {1, 2};
        int len = removeDuplicates(nums, 3);

        assert(len == 2);
        assert_prefix_equal(nums, expected, len);
    }

    {
        int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int expected[] = {0, 1, 2, 3, 4};
        int len = removeDuplicates(nums, 10);

        assert(len == 5);
        assert_prefix_equal(nums, expected, len);
    }
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("remove_duplicates_sorted_array.c: all tests passed\n");
    return 0;
}
#endif
