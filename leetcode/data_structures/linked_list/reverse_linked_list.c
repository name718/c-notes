#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：206
 * 题目：Reverse Linked List
 * 地址：https://leetcode.com/problems/reverse-linked-list/
 */

/*
 * 题目：反转链表
 * 难度：简单
 * 练习点：链表、指针反转、迭代/递归
 *
 * 题意（改写）：
 * 给定单链表头节点 head，反转链表并返回新的头节点。
 *
 * 算法描述：
 * 1. 用 prev、curr、next 三指针逐节点反转指向。
 * 2. 每轮保存 next，令 curr->next = prev。
 * 3. 循环结束后 prev 即新头节点。
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    (void)head;

    /* TODO: 在这里完成具体实现 */
    return NULL;
}
