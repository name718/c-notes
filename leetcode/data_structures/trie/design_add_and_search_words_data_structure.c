#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：211
 * 题目：Design Add and Search Words Data Structure
 * 地址：https://leetcode.com/problems/design-add-and-search-words-data-structure/
 */

/*
 * 题目：添加与搜索单词 - 数据结构设计
 * 难度：中等
 * 练习点：Trie、DFS、通配符匹配
 *
 * 题意（改写）：
 * 设计数据结构支持 addWord 和 search，search 支持 '.' 匹配任意单个字符。
 *
 * 算法描述：
 * 1. 用 Trie 存储所有单词。
 * 2. addWord 与普通插入一致。
 * 3. search 遇到 '.' 时对所有子节点做 DFS 分支匹配。
 */

typedef struct {
    int placeholder;
} WordDictionary;

WordDictionary *wordDictionaryCreate(void)
{
    /* TODO: 在这里完成具体实现 */
    return NULL;
}

void wordDictionaryAddWord(WordDictionary *obj, char *word)
{
    (void)obj;
    (void)word;

    /* TODO: 在这里完成具体实现 */
}

bool wordDictionarySearch(WordDictionary *obj, char *word)
{
    (void)obj;
    (void)word;

    /* TODO: 在这里完成具体实现 */
    return false;
}

void wordDictionaryFree(WordDictionary *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}
