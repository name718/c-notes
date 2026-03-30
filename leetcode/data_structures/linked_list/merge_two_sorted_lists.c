#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：21
 * 题目：Merge Two Sorted Lists
 * 地址：https://leetcode.com/problems/merge-two-sorted-lists/
 */

/*
 * 题目：合并两个有序链表
 * 难度：简单
 * 练习点：链表、双指针、迭代合并
 *
 * 题意（改写）：
 * 将两个升序链表合并为一个新的升序链表并返回头节点。
 *
 * 算法描述：
 * 1. 使用哑节点简化头节点处理。
 * 2. 比较两链表当前节点值，较小者接到结果尾部。
 * 3. 某一链表遍历结束后，直接连接另一条剩余部分。
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    (void)list1;
    (void)list2;

    /* TODO: 在这里完成具体实现 */
    return NULL;
}
