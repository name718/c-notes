#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * LeetCode 题号：141
 * 题目：Linked List Cycle
 * 地址：https://leetcode.com/problems/linked-list-cycle/
 */

/*
 * 题目：环形链表
 * 难度：简单
 * 练习点：快慢指针、链表判环
 *
 * 题意（改写）：
 * 判断链表中是否存在环。存在返回 true，否则返回 false。
 *
 * 算法描述：
 * 1. 使用快慢指针，慢指针每次走一步，快指针每次走两步。
 * 2. 若存在环，快慢指针最终会相遇。
 * 3. 若快指针到达空指针，说明无环。
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    (void)head;

    /* TODO: 在这里完成具体实现 */
    return false;
}
