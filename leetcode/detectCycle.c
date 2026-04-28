/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
// 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
// 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 不允许修改 链表。
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    // 1. 定义快慢指针
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // 2. 第一步：找相遇点，判断是否有环
    // 快指针走到头，说明无环
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // 慢指针走1步
        fast = fast->next->next;    // 快指针走2步
        
        // 相遇了！说明有环，跳出循环去找入口
        if (slow == fast) {
            // 3. 第二步：找环的入口
            // 公式：一个指针从头走，一个从相遇点走，速度相同，相遇就是入口
            struct ListNode *p = head;
            while (p != fast) {
                p = p->next;
                fast = fast->next;
            }
            return p; // 返回入环第一个节点
        }
    }

    // 4. 无环，返回NULL
    return NULL;
}