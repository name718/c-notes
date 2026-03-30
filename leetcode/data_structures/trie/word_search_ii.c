#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：212
 * 题目：Word Search II
 * 地址：https://leetcode.com/problems/word-search-ii/
 */

/*
 * 题目：单词搜索 II
 * 难度：困难
 * 练习点：Trie、回溯、剪枝、二维网格搜索
 *
 * 题意（改写）：
 * 给定字符网格 board 和单词列表 words，找出所有可在网格中由相邻字符构成的单词。
 *
 * 算法描述：
 * 1. 先将 words 建成 Trie。
 * 2. 从每个网格点启动 DFS 回溯，在 Trie 中同步匹配路径。
 * 3. 用访问标记避免重复使用同格，并在无前缀时及时剪枝。
 */

char **findWords(char **board,
                 int boardSize,
                 int *boardColSize,
                 char **words,
                 int wordsSize,
                 int *returnSize)
{
    (void)board;
    (void)boardSize;
    (void)boardColSize;
    (void)words;
    (void)wordsSize;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}
