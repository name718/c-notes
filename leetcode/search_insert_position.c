#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：35
 * 题目：Search Insert Position
 * 地址：https://leetcode.com/problems/search-insert-position/
 */

/*
 * 题目：搜索插入位置
 * 难度：简单
 * 练习点：有序数组、二分查找、边界处理
 *
 * 题意（改写）：
 * 给定一个按升序排列的整数数组 nums 和目标值 target。
 * 如果目标值存在，返回它的下标；
 * 如果不存在，返回它应当插入的位置下标。
 *
 * 要求尽量用对数时间复杂度完成。
 *
 * 示例：
 * 输入：nums = [1,3,5,6], target = 5
 * 输出：2
 */

int searchInsert(int *nums, int numsSize, int target)
{
    (void)nums;
    (void)numsSize;
    (void)target;

    /* TODO: 在这里完成具体实现 */
    return -1;
}

static void run_tests(void)
{
    int nums[] = {1, 3, 5, 6};

    assert(searchInsert(nums, 4, 5) == 2);
    assert(searchInsert(nums, 4, 2) == 1);
    assert(searchInsert(nums, 4, 7) == 4);
    assert(searchInsert(nums, 4, 0) == 0);
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    run_tests();
    printf("search_insert_position.c: all tests passed\n");
    return 0;
}
#endif
