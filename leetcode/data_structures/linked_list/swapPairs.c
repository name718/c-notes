/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    // 1. 创建虚拟头节点，指向原链表头
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    // prev 始终指向待交换两个节点的前驱节点
    struct ListNode* prev = dummy;
    
    // 循环条件：后面有两个节点才需要交换
    while (prev->next != NULL && prev->next->next != NULL) {
        // 定义两个待交换节点：first 第一个，second 第二个
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;
        
        // 核心：三步完成交换
        first->next = second->next;  // 1. 第一个节点指向第二个节点的下一个
        second->next = first;        // 2. 第二个节点指向第一个节点（完成交换）
        prev->next = second;         // 3. 前驱节点指向新的第一个节点（连接链表）
        
        // prev 后移两位，准备下一组交换
        prev = first;
    }
    
    // 新的头节点是虚拟头的下一个
    struct ListNode* newHead = dummy->next;
    free(dummy);  // 释放虚拟头，避免内存泄漏
    return newHead;
}