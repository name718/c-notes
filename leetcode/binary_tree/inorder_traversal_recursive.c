#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：94
 * 题目：Binary Tree Inorder Traversal
 * 地址：https://leetcode.cn/problems/binary-tree-inorder-traversal/
 */

/*
 * 题目：二叉树的中序遍历（递归）
 * 难度：简单
 * 练习点：递归、DFS、二叉树遍历顺序
 *
 * 题意（改写）：
 * 给你二叉树的根节点 root，返回它节点值的中序遍历。
 * 中序遍历顺序：左 -> 根 -> 右。
 *
 * 算法描述（递归版）：
 * 1. 递归访问左子树。
 * 2. 访问当前节点并记录值。
 * 3. 递归访问右子树。
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *inorderTraversal(struct TreeNode *root, int *returnSize)
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
    printf("inorder_traversal_recursive.c template ready\n");
    return 0;
}
#endif
