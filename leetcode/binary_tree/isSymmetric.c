/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 辅助函数：比较两个子树是否对称
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // 两个子树都为空，对称
    if (left == NULL && right == NULL) return true;
    // 其中一个为空，另一个不为空，不对称
    if (left == NULL || right == NULL) return false;
    // 节点值相等，且左子树的左与右子树的右对称、左子树的右与右子树的左对称
    return (left->val == right->val) 
        && isMirror(left->left, right->right) 
        && isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    // 空树是对称的
    if (root == NULL) return true;
    // 比较根节点的左右子树是否对称
    return isMirror(root->left, root->right);
}