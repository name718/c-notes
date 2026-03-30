#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：208
 * 题目：Implement Trie (Prefix Tree)
 * 地址：https://leetcode.com/problems/implement-trie-prefix-tree/
 */

/*
 * 题目：实现 Trie (前缀树)
 * 难度：中等
 * 练习点：字典树、字符串、节点设计
 *
 * 题意（改写）：
 * 设计 Trie，支持 insert、search、startsWith。
 *
 * 算法描述：
 * 1. 每个节点维护 26 个子节点指针和单词结束标记。
 * 2. insert 逐字符创建/复用子节点。
 * 3. search/startsWith 按路径查找并判断结束标记或路径是否存在。
 */

typedef struct {
    int placeholder;
} Trie;

Trie *trieCreate(void)
{
    /* TODO: 在这里完成具体实现 */
    return NULL;
}

void trieInsert(Trie *obj, char *word)
{
    (void)obj;
    (void)word;

    /* TODO: 在这里完成具体实现 */
}

bool trieSearch(Trie *obj, char *word)
{
    (void)obj;
    (void)word;

    /* TODO: 在这里完成具体实现 */
    return false;
}

bool trieStartsWith(Trie *obj, char *prefix)
{
    (void)obj;
    (void)prefix;

    /* TODO: 在这里完成具体实现 */
    return false;
}

void trieFree(Trie *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}
