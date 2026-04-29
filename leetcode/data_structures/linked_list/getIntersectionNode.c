#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
   int val;
   struct ListNode *next;
};


// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    
    // 当 a 和 b 相遇时停止（可能是交点，也可能是 NULL）
    while (a != b) {
        // a 走一步，如果到末尾就切换到 headB
        a = (a == NULL) ? headB : a->next;
        // b 走一步，如果到末尾就切换到 headA
        b = (b == NULL) ? headA : b->next;
    }
    
    // 相遇点就是交点（如果没有交点，最终 a == b == NULL）
    return a;
}