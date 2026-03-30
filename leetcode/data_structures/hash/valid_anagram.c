#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * LeetCode 题号：242
 * 题目：Valid Anagram
 * 地址：https://leetcode.com/problems/valid-anagram/
 */

/*
 * 题目：有效的字母异位词
 * 难度：简单
 * 练习点：哈希计数、字符频次、字符串
 *
 * 题意（改写）：
 * 给定两个字符串 s 和 t，判断 t 是否是 s 的字母异位词。
 *
 * 算法描述：
 * 1. 统计 s 中每个字符出现次数。
 * 2. 遍历 t 并抵消计数。
 * 3. 所有字符计数最终为 0 则为异位词。
 */

bool isAnagram(char *s, char *t)
{
    (void)s;
    (void)t;

    /* TODO: 在这里完成具体实现 */
    return false;
}
