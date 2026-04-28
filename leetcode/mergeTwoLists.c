/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // 1. 创建虚拟头节点
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = NULL;
    
    // 2. 用 cur 指针穿节点
    struct ListNode* cur = dummy;
    
    // 3. 穿两个链表
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            cur->next = list1;   // 小的接后面
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next; // 指针向后走
    }
    
    // 4. 拼接剩下的
    if (list1 != NULL) cur->next = list1;
    if (list2 != NULL) cur->next = list2;
    
    // 5. 返回真正的链表头
    return dummy->next;
}