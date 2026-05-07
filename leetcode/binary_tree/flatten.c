/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 给你二叉树的根结点 root ，请你将它展开为一个单链表：

// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。
// void flatten(struct TreeNode *root)
// {
//     if (!root)
//         return;

//     struct TreeNode **stack = malloc(sizeof(struct TreeNode *) * 1000);
//     int top = 0;
//     stack[top++] = root;

//     struct TreeNode *prev = NULL;

//     while (top > 0)
//     {
//         struct TreeNode *cur = stack[--top];

//         // 拼接链表
//         if (prev)
//         {
//             prev->right = cur;
//             prev->left = NULL;
//         }
//         prev = cur;

//         // 先压右，再压左 → 出栈就是先序
//         if (cur->right)
//             stack[top++] = cur->right;
//         if (cur->left)
//             stack[top++] = cur->left;
//     }

//     free(stack);
// }

void flatten(struct TreeNode *root)
{
    if (root == NULL) return;

    struct TreeNode **stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int top = 0;
    stack[top++] = root;  // 根节点先入栈

    struct TreeNode *prev = NULL;

    while (top > 0)
    {
        struct TreeNode *cur = stack[--top];  // 出栈

        // 拼接链表（原地修改，不新建节点）
        if (prev != NULL) {
            prev->right = cur;
            prev->left = NULL;
        }
        prev = cur;

        // 先压右，再压左 → 出栈就是先序
        if (cur->right) {
            stack[top++] = cur->right;
        }
        if (cur->left) {
            stack[top++] = cur->left;
        }
    }

    free(stack);
}