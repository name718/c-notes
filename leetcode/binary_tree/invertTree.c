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

struct TreeNode *invertTree(struct TreeNode *root) {
    // 递归终止条件：空节点直接返回
    if (root == NULL) {
        return NULL;
    }

    // 交换当前节点的左右子节点
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 递归翻转左子树和右子树
    invertTree(root->left);
    invertTree(root->right);

    // 返回当前节点
    return root;
}