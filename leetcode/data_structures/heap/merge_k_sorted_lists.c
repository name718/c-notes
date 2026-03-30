#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：23
 * 题目：Merge k Sorted Lists
 * 地址：https://leetcode.com/problems/merge-k-sorted-lists/
 */

/*
 * 题目：合并 K 个升序链表
 * 难度：困难
 * 练习点：最小堆、多路归并、链表
 *
 * 题意（改写）：
 * 给你一个链表数组，每个链表都按升序排列，请合并所有链表并返回头节点。
 *
 * 算法描述：
 * 1. 将每个非空链表头节点放入最小堆。
 * 2. 每次弹出最小节点接到结果链表尾部。
 * 3. 若弹出节点有 next，将 next 再入堆。
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    (void)lists;
    (void)listsSize;

    /* TODO: 在这里完成具体实现 */
    return NULL;
}
