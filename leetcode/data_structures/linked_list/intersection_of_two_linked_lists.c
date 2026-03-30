#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：160
 * 题目：Intersection of Two Linked Lists
 * 地址：https://leetcode.com/problems/intersection-of-two-linked-lists/
 */

/*
 * 题目：相交链表
 * 难度：简单
 * 练习点：链表、双指针、长度对齐
 *
 * 题意（改写）：
 * 给定两个单链表头节点，返回它们相交的起始节点；若不相交返回 NULL。
 *
 * 算法描述：
 * 1. 双指针分别从两链表头出发。
 * 2. 到达末尾后切换到另一条链表头。
 * 3. 若相交最终在交点相遇，否则同时到达 NULL。
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    (void)headA;
    (void)headB;

    /* TODO: 在这里完成具体实现 */
    return NULL;
}
