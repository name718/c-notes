#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：704
 * 题目：Binary Search
 * 地址：https://leetcode.cn/problems/binary-search/
 */

/*
 * 题目：二分查找
 * 难度：简单
 * 练习点：有序数组、循环、二分查找、边界处理
 *
 * 题意（改写）：
 * 给定一个按升序排列的整数数组 nums，和一个目标值 target。
 * 如果 target 存在，返回它的下标；如果不存在，返回 -1。
 *
 * 要求使用 O(log n) 的时间复杂度。
 *
 * 示例：
 * 输入：nums = [-1,0,3,5,9,12], target = 9
 * 输出：4
 */

int search(int *nums, int numsSize, int target)
{
    (void)nums;
    (void)numsSize;
    (void)target;

    /* TODO: 在这里完成具体实现 */
    int left = 0;
    int right = numsSize - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (target < nums[mid]) {
            right = mid - 1;
        }
        if (target > nums[mid]) {
            left = mid + 1;
        }
    }
    return -1;
}

static void run_tests(void)
{
    int nums[] = {-1, 0, 3, 5, 9, 12};

    assert(search(nums, 6, 9) == 4);
    assert(search(nums, 6, 2) == -1);
    assert(search(nums, 6, -1) == 0);
    assert(search(nums, 6, 12) == 5);
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("binary_search.c: all tests passed\n");
    return 0;
}
#endif
