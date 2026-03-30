#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：102
 * 题目：Binary Tree Level Order Traversal
 * 地址：https://leetcode.cn/problems/binary-tree-level-order-traversal/
 */

/*
 * 题目：二叉树的层序遍历
 * 难度：中等
 * 练习点：队列、BFS、按层分组
 *
 * 题意（改写）：
 * 给你二叉树的根节点 root，返回其节点值的层序遍历结果。
 * 也就是逐层从左到右访问所有节点。
 *
 * 算法描述：
 * 1. 使用队列进行广度优先搜索。
 * 2. 每轮先记录当前层节点数量，再处理这一整层。
 * 3. 每层结果单独存入二维数组，同时维护 returnColumnSizes。
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    (void)root;

    if (returnSize != NULL) {
        *returnSize = 0;
    }
    if (returnColumnSizes != NULL) {
        *returnColumnSizes = NULL;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("level_order_traversal.c template ready\n");
    return 0;
}
#endif
