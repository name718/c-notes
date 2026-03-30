#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：75
 * 题目：Sort Colors
 * 地址：https://leetcode.cn/problems/sort-colors/
 */

/*
 * 题目：颜色分类
 * 难度：中等
 * 练习点：三指针、原地排序、荷兰国旗问题
 *
 * 题意（改写）：
 * 给定一个包含红色、白色和蓝色（分别用 0、1、2 表示）的数组 nums，
 * 请原地对它们进行排序，使相同颜色元素相邻，并按 0、1、2 顺序排列。
 *
 * 算法描述（三指针）：
 * 1. 维护 low、mid、high 三个指针。
 * 2. 根据 nums[mid] 的值与 low/high 位置交换并移动指针。
 * 3. 一次线性扫描完成原地排序。
 */

void sortColors(int *nums, int numsSize)
{
    (void)nums;
    (void)numsSize;

    /* TODO: 在这里完成具体实现 */
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("sort_colors.c template ready\n");
    return 0;
}
#endif
