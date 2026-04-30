/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 给你一棵二叉树的根节点，返回该树的 直径 。

// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

// 两节点之间路径的 长度 由它们之间边数表示。

#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int treeDepth(struct TreeNode *root);
static int s_max;

int diameterOfBinaryTree(struct TreeNode *root)
{
    s_max = 0;
    treeDepth(root);
    return s_max;
}

int treeDepth(struct TreeNode *root){
    if (root == NULL) return 0;
    int left_dep = treeDepth(root->left);
    int right_dep = treeDepth(root->right);

    if(left_dep + right_dep > s_max) {
        s_max = left_dep + right_dep;
    }

    return 1 + (left_dep >right_dep ? left_dep : right_dep);
}