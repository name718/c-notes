#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * LeetCode 题号：179
 * 题目：Largest Number
 * 地址：https://leetcode.cn/problems/largest-number/
 */

/*
 * 题目：最大数
 * 难度：中等
 * 练习点：自定义排序、字符串比较、边界处理
 *
 * 题意（改写）：
 * 给定一组非负整数 nums，重新排列它们的顺序，
 * 使其拼接成的整数最大，并以字符串形式返回结果。
 *
 * 算法描述：
 * 1. 将整数转为字符串。
 * 2. 自定义排序规则：比较 a+b 与 b+a 的字典序决定先后。
 * 3. 排序后拼接；若最高位为 "0"，直接返回 "0"。
 */

void itoa(int n, char s[]) {
    int i = 0, sign = n;
    if (n < 0) n = -n;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';

    // 反转字符串
    int j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        char c = s[i]; s[i] = s[j]; s[j] = c;
    }
}

// 比较函数：判断是否应该将 a 排在 b 前面
int compare(const void *a, const void *b) {
    char *str_a = *(char **)a;
    char *str_b = *(char **)b;
    
    // 计算拼接后的字符串长度
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);
    int len_ab = len_a + len_b + 1;
    int len_ba = len_b + len_a + 1;
    
    char *ab = (char *)malloc(len_ab);
    char *ba = (char *)malloc(len_ba);
    
    // 拼接 a+b 和 b+a
    strcpy(ab, str_a);
    strcat(ab, str_b);
    
    strcpy(ba, str_b);
    strcat(ba, str_a);
    
    // 比较字典序（降序，大的在前）
    int result = strcmp(ba, ab);
    
    free(ab);
    free(ba);
    
    return result;
}

char *largestNumber(int *nums, int numsSize)
{
    if (numsSize == 0) {
        char *result = (char *)malloc(2);
        strcpy(result, "0");
        return result;
    }
    
    // 分配字符串数组
    char **strs = (char **)malloc(numsSize * sizeof(char *));
    for (int i = 0; i < numsSize; i++) {
        strs[i] = (char *)malloc(12 * sizeof(char)); // int 最大 10 位 + 符号位 + 结束符
        itoa(nums[i], strs[i]);
    }
    
    // 排序
    qsort(strs, numsSize, sizeof(char *), compare);
    
    // 检查是否全为 0
    if (strcmp(strs[0], "0") == 0) {
        char *result = (char *)malloc(2);
        strcpy(result, "0");
        // 释放内存
        for (int i = 0; i < numsSize; i++) {
            free(strs[i]);
        }
        free(strs);
        return result;
    }
    
    // 计算结果字符串长度
    int total_len = 0;
    for (int i = 0; i < numsSize; i++) {
        total_len += strlen(strs[i]);
    }
    
    // 拼接结果
    char *result = (char *)malloc((total_len + 1) * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strs[i]);
    }
    
    // 释放内存
    for (int i = 0; i < numsSize; i++) {
        free(strs[i]);
    }
    free(strs);
    
    return result;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("largest_number.c template ready\n");
    
    // 测试用例 1
    int nums1[] = {10, 20, 0, 40};
    int len1 = sizeof(nums1) / sizeof(int);
    char *result1 = largestNumber(nums1, len1);
    printf("测试1 结果: %s\n", result1);
    free(result1);
    
    // 测试用例 2
    int nums2[] = {3, 30, 34, 5, 9};
    int len2 = sizeof(nums2) / sizeof(int);
    char *result2 = largestNumber(nums2, len2);
    printf("测试2 结果: %s\n", result2);
    free(result2);
    
    // 测试用例 3
    int nums3[] = {0, 0};
    int len3 = sizeof(nums3) / sizeof(int);
    char *result3 = largestNumber(nums3, len3);
    printf("测试3 结果: %s\n", result3);
    free(result3);
    
    return 0;
}
#endif