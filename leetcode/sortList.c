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

struct ListNode* sortList(struct ListNode* head) {
    // 1. 边界防护：如果链表为空或只有一个节点，直接返回
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 2. 创建哨兵节点（Dummy Node），排在头节点前面
    // 这让所有插入操作都能统一处理，不用单独判断是否要替换头节点
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0; 
    dummy->next = head;

    // lastSorted: 永远指向已排序区域的最后一个节点
    struct ListNode* lastSorted = head;
    // curr: 当前准备考察并插入的节点（即未排序区域的第一个节点）
    struct ListNode* curr = head->next;

    while (curr != NULL) {
        // 情况 A：如果当前节点比已排序的最后一个节点大，直接留在原位，扩展已排序区域
        if (lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next;
        } 
        // 情况 B：当前节点比较小，需要往前找位置插入
        else {
            // 从哨兵节点开始往后找，寻找合适的前驱节点 (prev)
            struct ListNode* prev = dummy;
            
            // 只要 prev 的下一个节点的值比 curr 小，就继续往后走
            while (prev->next->val <= curr->val) {
                prev = prev->next;
            }

            // 此时找到了插入位置：应该把 curr 插入到 prev 和 prev->next 之间
            
            // 第一步：把 curr 从原位置“剪”下来，并让 lastSorted 连上 curr 后面的节点
            lastSorted->next = curr->next;
            
            // 第二步：把 curr 缝合到 prev 后面
            curr->next = prev->next;
            prev->next = curr;
        }
        
        // 处理完一个节点后，更新 curr 为下一个待处理的节点
        curr = lastSorted->next;
    }

    // 记录真正的头节点
    struct ListNode* sortedHead = dummy->next;
    
    // 释放辅助用的哨兵节点内存，防止内存泄漏
    free(dummy);
    
    return sortedHead;
}