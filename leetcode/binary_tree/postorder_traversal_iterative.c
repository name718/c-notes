#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：145
 * 题目：Binary Tree Postorder Traversal
 * 地址：https://leetcode.cn/problems/binary-tree-postorder-traversal/
 */

/*
 * 题目：二叉树的后序遍历（非递归）
 * 难度：简单
 * 练习点：栈、迭代 DFS、访问顺序控制
 *
 * 题意（改写）：
 * 给你二叉树的根节点 root，返回它节点值的后序遍历。
 * 后序遍历顺序：左 -> 右 -> 根。
 *
 * 算法描述（非递归版）：
 * 1. 使用栈辅助遍历，并维护节点访问状态。
 * 2. 先沿左链入栈，再根据右子树是否处理过决定弹栈时机。
 * 3. 仅在左右子树都处理后记录当前节点值。
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
    printf("postorder_traversal_iterative.c template ready\n");
    return 0;
}
#endif
