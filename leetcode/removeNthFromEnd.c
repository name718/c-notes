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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // 1. 创建虚拟头节点（关键！解决边界问题）
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* slow = dummy;
    struct ListNode* fast = dummy;

    // 2. 快指针先走 n+1 步
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // 3. 快慢一起走
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // 4. 删除节点
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    // 5. 返回真正头
    return dummy->next;
}

// #include <stdlib.h>
// // 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

// struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//     struct ListNode* slow = head;
//     struct ListNode* fast = head;

//     while (fast != NULL && n != 0)
//     {
//         n --;
//         fast = fast->next;
//     }
    
//     while (fast != NULL)
//     {
//         fast = fast->next;
//         slow = slow->next;
//     }

//     struct ListNode* temp = slow->next->next;
//     slow->next = temp;
    
//     return head;
// }