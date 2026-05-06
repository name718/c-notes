/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 非递归 + 栈 + 中序遍历，找 BST 第 k 小元素
int kthSmallest(struct TreeNode* root, int k) {
    // 开一个栈，存放树节点指针
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int top = 0; // 栈顶指针，初始为0（空栈）

    while (top > 0 || root != NULL) {
        // 1. 一路向左走，全部入栈
        while (root != NULL) {
            stack[top++] = root; // 节点入栈
            root = root->left;
        }

        // 2. 出栈 = 中序访问
        root = stack[--top];
        k--;
        if (k == 0) {
            free(stack);
            return root->val; // 找到第 k 小，直接返回
        }

        // 3. 转向右子树
        root = root->right;
    }

    free(stack);
    return -1; // 不会走到这里
}