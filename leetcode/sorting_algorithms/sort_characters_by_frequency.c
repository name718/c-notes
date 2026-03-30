#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：451
 * 题目：Sort Characters By Frequency
 * 地址：https://leetcode.com/problems/sort-characters-by-frequency/
 */

/*
 * 题目：根据字符出现频率排序
 * 难度：中等
 * 练习点：计数、桶排序、字符串构造
 *
 * 题意（改写）：
 * 给定一个字符串 s，请按字符出现频率降序重新排列字符串并返回结果。
 *
 * 算法描述：
 * 1. 统计每个字符出现次数。
 * 2. 按频率分桶，或对字符数组按频率自定义排序。
 * 3. 按频率从高到低拼接字符构造结果字符串。
 */

char *frequencySort(char *s)
{
    (void)s;

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("sort_characters_by_frequency.c template ready\n");
    return 0;
}
#endif
