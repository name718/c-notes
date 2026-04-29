/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

// 题目标准的节点定义（包含 random 指针）
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // ==========================================
    // 第一步：穿插克隆。在每个老房子后面建一个新房子
    // 效果：A -> A' -> B -> B' -> C -> C'
    // ==========================================
    struct Node* current = head;
    while (current != NULL) {
        // 1. 申请新内存（买蓝砖）
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = current->val;
        
        // 2. 插入到当前节点和下一个节点之间
        newNode->next = current->next;
        current->next = newNode;
        
        // 3. 移动到下一个老房子（因为中间插了一个新节点，所以要跳两步）
        current = newNode->next;
    }

    // ==========================================
    // 第二步：复制飞镖（random 指针）
    // 核心逻辑：新房子的飞镖目标 = 老房子飞镖目标的下一个
    // ==========================================
    current = head; // 重新回到链表头
    while (current != NULL) {
        if (current->random != NULL) {
            // current->next 是新房子
            // current->random->next 是老房子飞镖目标的下一个（也就是目标的新房子）
            current->next->random = current->random->next;
        } else {
            current->next->random = NULL;
        }
        // 每次跳过新节点，移动到下一个老房子
        current = current->next->next;
    }

    // ==========================================
    // 第三步：过河拆桥（拆分链表）
    // 任务：把混合链表拆成两条，恢复老链表，提取新链表
    // ==========================================
    current = head;
    struct Node* newHead = head->next; // 记录新链表的头节点，准备最后返回
    struct Node* copyCurrent = newHead;

    while (current != NULL) {
        // 1. 修复老房子的 next 指针，跳过新房子
        current->next = current->next->next;
        
        // 2. 提取新房子的 next 指针，跳过老房子（需判断是否到达末尾）
        if (copyCurrent->next != NULL) {
            copyCurrent->next = copyCurrent->next->next;
        }
        
        // 3. 齐步走，向后推进
        current = current->next;
        copyCurrent = copyCurrent->next;
    }

    // 返回组装好的全新链表头节点
    return newHead;
}