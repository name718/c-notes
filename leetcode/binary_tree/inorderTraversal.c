/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int max = 10000;

    int *ans = (int *)malloc(sizeof(int) * max);
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * max);

    int stack_size = 0;

    while (stack_size > 0 || root != NULL)
    {
        // 一直往左走
        while (root != NULL)
        {
            stack[stack_size++] = root;
            root = root->left;
        }

        // 弹栈
        struct TreeNode *pop = stack[--stack_size];
        ans[(*returnSize)++] = pop->val;

        // 转向右子树（关键修复点）
        root = pop->right;
    }

    return ans;
}