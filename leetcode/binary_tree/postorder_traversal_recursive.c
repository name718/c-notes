#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：145
 * 题目：Binary Tree Postorder Traversal
 * 地址：https://leetcode.cn/problems/binary-tree-postorder-traversal/
 */

/*
 * 题目：二叉树的后序遍历（递归）
 * 难度：简单
 * 练习点：递归、DFS、二叉树遍历顺序
 *
 * 题意（改写）：
 * 给你二叉树的根节点 root，返回它节点值的后序遍历。
 * 后序遍历顺序：左 -> 右 -> 根。
 *
 * 算法描述（递归版）：
 * 1. 递归遍历左子树。
 * 2. 递归遍历右子树。
 * 3. 最后访问当前节点。
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *postorderTraversal(struct TreeNode *root, int *returnSize)
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
    printf("postorder_traversal_recursive.c template ready\n");
    return 0;
}
#endif
