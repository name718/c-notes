/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curry = res;
    struct ListNode* p = l1;
    struct ListNode* q = l2;

    res->val = 0;
    res->next = NULL;

    int carry = 0;

    // 改动1：循环加上 carry，处理最后多余进位
    while (q != NULL || p != NULL || carry != 0)
    {
       int val1 = p == NULL ? 0 : p->val;
       int val2 = q == NULL ? 0 : q->val;

       int sum = carry + val1 + val2;
       carry = sum / 10;

       struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
       temp->val = sum % 10;
       temp->next = NULL;
       curry->next = temp;

       // 改动2：curry 后移，不然只会在同一个节点反复覆盖
       curry = curry->next;

       if (p) p = p->next;
       if (q) q = q->next;
    }
    // 改动3：res 是虚拟头，要返回下一个才是真实结果
    return res->next;
}