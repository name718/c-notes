#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * LeetCode 题号：26
 * 题目：Remove Duplicates from Sorted Array
 */

int removeDuplicates(int *nums, int numsSize)
{
    // 数组为空直接返回 0
    if (numsSize == 0) {
        return 0;
    }

    // 慢指针：指向新数组最后一个位置
    int slow = 0;

    // 快指针：遍历整个数组
    for (int fast = 1; fast < numsSize; fast++) {
        // 发现不一样的数字，就把它放到慢指针下一位
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }

    // 新长度 = slow + 1
    return slow + 1;
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
