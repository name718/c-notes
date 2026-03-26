#include <assert.h>
#include <stdio.h>

/*
 * 题目：合并两个有序数组
 * 难度：简单
 * 练习点：数组、双指针、下标、原地修改
 *
 * 题意（改写）：
 * 给你两个按非递减顺序排列的整数数组 nums1 和 nums2。
 * nums1 的长度是 m + n，其中前 m 个元素有效，后 n 个位置预留给 nums2。
 * 请把 nums2 合并到 nums1 中，并保持结果仍然有序。
 *
 * 示例：
 * 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出：nums1 = [1,2,2,3,5,6]
 */

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    (void)nums1;
    (void)nums1Size;
    (void)m;
    (void)nums2;
    (void)nums2Size;
    (void)n;

    /* TODO: 在这里完成具体实现 */
    int i = m - 1; // nums1 的最后一个有效元素下标
    int j = n - 1; // nums2 的最后一个元素下标
    int k = m + n - 1; // nums1 的最后一个位置下标
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];    
    }
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
        int nums1[] = {1, 2, 3, 0, 0, 0};
        int nums2[] = {2, 5, 6};
        int expected[] = {1, 2, 2, 3, 5, 6};

        merge(nums1, 6, 3, nums2, 3, 3);
        assert_array_equal(nums1, expected, 6);
    }

    {
        int nums1[] = {1};
        int *nums2 = NULL;
        int expected[] = {1};

        merge(nums1, 1, 1, nums2, 0, 0);
        assert_array_equal(nums1, expected, 1);
    }

    {
        int nums1[] = {0};
        int nums2[] = {1};
        int expected[] = {1};

        merge(nums1, 1, 0, nums2, 1, 1);
        assert_array_equal(nums1, expected, 1);
    }
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("merge.c: all tests passed\n");
    return 0;
}
#endif
