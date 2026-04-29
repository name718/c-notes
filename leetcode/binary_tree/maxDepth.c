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
int maxDepth(struct TreeNode *root)
{
    // 递归终止条件：空节点深度为0
    if (root == NULL)
    {
        return 0;
    }
    // 递归计算左子树和右子树的深度
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    // 当前节点的深度 = 1 + 左右子树深度的最大值
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}