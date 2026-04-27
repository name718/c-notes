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

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *h = NULL; // h 用来充当反转后新链表的头节点

    while (head) {
        // 1. 先把原链表的下一个节点保存下来，防止走丢！
        struct ListNode *next_node = head->next; 
        
        // 2. 将当前节点从原链表摘下，头插到新链表 h 的前面
        head->next = h;
        
        // 3. 更新新链表的头节点为当前节点
        h = head;
        
        // 4. head 指针往后挪一步，处理下一个节点
        head = next_node;
    }
    
    // 5. 不要忘记返回反转后的新头节点
    return h;
}