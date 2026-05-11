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

// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // 递归终止条件：空节点 或 找到p/q，直接返回
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // 递归查左子树
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    // 递归查右子树
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // 情况1：左右都不为空 → 当前root就是最近公共祖先
    if (left != NULL && right != NULL) {
        return root;
    }

    // 情况2：左边空 → 答案在右边
    if (left == NULL) {
        return right;
    }

    // 情况3：右边空 → 答案在左边
    return left;
}