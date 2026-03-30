#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：144
 * 题目：Binary Tree Preorder Traversal
 * 地址：https://leetcode.com/problems/binary-tree-preorder-traversal/
 */

/*
 * 题目：二叉树的前序遍历（递归）
 * 难度：简单
 * 练习点：递归、DFS、二叉树遍历顺序
 *
 * 题意（改写）：
 * 给你二叉树的根节点 root，返回它节点值的前序遍历。
 * 前序遍历顺序：根 -> 左 -> 右。
 *
 * 算法描述（递归版）：
 * 1. 处理空节点边界。
 * 2. 先访问当前节点值，再递归左子树，再递归右子树。
 * 3. 用动态数组收集结果，并通过 returnSize 返回长度。
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
    printf("preorder_traversal_recursive.c template ready\n");
    return 0;
}
#endif
