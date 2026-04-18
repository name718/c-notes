#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：94
 * 题目：Binary Tree Inorder Traversal
 * 地址：https://leetcode.cn/problems/binary-tree-inorder-traversal/
 */

/*
 * 题目：二叉树的中序遍历（非递归）
 * 难度：简单
 * 练习点：栈、迭代 DFS、二叉树遍历顺序
 *
 * 题意（改写）：
 * 给你二叉树的根节点 root，返回它节点值的中序遍历。
 * 中序遍历顺序：左 -> 根 -> 右。
 *
 * 算法描述（非递归版）：
 * 1. 用栈维护从根到当前节点的路径。
 * 2. 持续向左下走并入栈。
 * 3. 到达空节点后弹栈访问，再转向右子树。
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // 修复 2：必须先将返回值大小初始化为 0
    *returnSize = 0; 
    
    // 如果是空树，直接返回 NULL
    if (root == NULL) return NULL;

    int size = 1000;
    struct TreeNode** stack = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    int *res = (int *)malloc(size * sizeof(int));
    
    // 修复 3：简化初始化逻辑，直接从 root 开始即可
    struct TreeNode* current = root; 
    int top = 0;

    while (top > 0 || current != NULL)
    {
        // 1. 一直向左深入，沿途节点全部压栈
        while (current != NULL)
        {
            stack[top++] = current;
            current = current->left;
        }

        // 2. 修复 1：先让 top 减 1，再取栈顶元素
        current = stack[--top]; 
        
        // 将值放入结果数组，并更新记录的数量
        res[(*returnSize)++] = current->val;

        // 3. 转向右子树
        current = current->right;
    }
    
    free(stack); // 别忘了释放申请的栈内存
    return res;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("inorder_traversal_iterative.c template ready\n");
    return 0;
}
#endif
