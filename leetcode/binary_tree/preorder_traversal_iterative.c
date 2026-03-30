#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：144
 * 题目：Binary Tree Preorder Traversal
 * 地址：https://leetcode.com/problems/binary-tree-preorder-traversal/
 */

/*
 * 题目：二叉树的前序遍历（非递归）
 * 难度：简单
 * 练习点：栈、迭代 DFS、二叉树遍历顺序
 *
 * 题意（改写）：
 * 给你二叉树的根节点 root，返回它节点值的前序遍历。
 * 前序遍历顺序：根 -> 左 -> 右。
 *
 * 算法描述（非递归版）：
 * 1. 使用栈模拟递归调用过程。
 * 2. 每次弹出节点时先记录节点值。
 * 3. 先压右子节点，再压左子节点，确保左子树先处理。
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    (void)root;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("preorder_traversal_iterative.c template ready\n");
    return 0;
}
#endif
