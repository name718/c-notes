#include <stdio.h>
#include <stdbool.h>

/*
 * LeetCode 题号：2855
 * 题目：Minimum Right Shifts to Sort the Array
 * 地址：https://leetcode.cn/problems/minimum-right-shifts-to-sort-the-array/
 */

// 判断是否是升序数组
bool isSortedAsc(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    return true;
}

// 核心函数：返回最少右移次数，无法返回 -1
int minimumRightShifts(int* nums, int numsSize) {
    // 1. 已经有序 → 0 次
    if (isSortedAsc(nums, numsSize)) {
        return 0;
    }

    // 2. 找到“下降点”（断崖）
    int breakIndex = -1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            breakIndex = i;
            break;
        }
    }

    // 3. 检查断崖之后是否一直递增
    for (int i = breakIndex + 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            return -1; // 多个断崖 → 不可能
        }
    }

    // 4. 检查最后一个元素 < 第一个元素
    if (nums[numsSize - 1] > nums[0]) {
        return -1;
    }

    // 5. 计算右移次数
    return numsSize - breakIndex;
}

// 测试主函数
int main(void) {
    int arr[5] = {3, 4, 5, 1, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    int res = minimumRightShifts(arr, len);
    printf("最少右移次数：%d\n", res);  // 输出 2
    
    return 0;
}
