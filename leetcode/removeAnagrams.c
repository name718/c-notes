#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 * LeetCode 题号：2273
 * 题目：Find Resultant Array After Removing Anagrams
 * 地址：https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
 */

// 给你一个下标从 0 开始的字符串数组 words ，其中 words[i] 由小写英文字符组成。

// 在一步操作中，需要选出任一下标 i ，从 words 中 删除 words[i] 。其中下标 i 需要同时满足下述两个条件：

//     0 < i < words.length
//     words[i - 1] 和 words[i] 是 字母异位词 。

// 只要可以选出满足条件的下标，就一直执行这个操作。

// 在执行所有操作后，返回 words 。可以证明，按任意顺序为每步操作选择下标都会得到相同的结果。

// 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。例如，"dacb" 是 "abdc" 的一个字母异位词。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmpChar(const void *left, const void *right) {
    return *(const char *)left - *(const char *)right;
}

// 判断是不是异位词
bool isAnagramc(const char *s1, const char *s2) {
    int len1 = (int)strlen(s1);
    int len2 = (int)strlen(s2);
    if (len1 != len2) {
        return false;
    }

    char *a = (char *)malloc((len1 + 1) * sizeof(char));
    char *b = (char *)malloc((len2 + 1) * sizeof(char));
    if (a == NULL || b == NULL) {
        free(a);
        free(b);
        return false;
    }

    strcpy(a, s1);
    strcpy(b, s2);

    qsort(a, len1, sizeof(char), cmpChar);
    qsort(b, len2, sizeof(char), cmpChar);

    bool isSame = strcmp(a, b) == 0;
    free(a);
    free(b);
    return isSame;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    // 判断是不是异位词
    // 1、qsort排序
    // 2、strcmp 比较
    char **result = malloc(wordsSize * sizeof(char *));
    int count = 0;

    for (int index = 0; index < wordsSize; index++) {
        if (index == 0) {
            result[count] = words[index];
            count += 1;
            continue;
        }

        if (!isAnagramc(words[index], result[count - 1])) {
            result[count] = words[index];
            count += 1;
        }
    }
    *returnSize = count;
    return result;
}
