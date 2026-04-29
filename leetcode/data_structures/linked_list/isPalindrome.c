/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//  给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // 1️⃣ 找中点
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2️⃣ 奇数长度：跳过中间节点
    if (fast) {
        slow = slow->next;
    }

    // 3️⃣ 反转后半部分
    struct ListNode *prev = NULL;
    while (slow) {
        struct ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // 4️⃣ 前后比较
    struct ListNode *left = head;
    struct ListNode *right = prev;

    while (right) {
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }

    return true;
}