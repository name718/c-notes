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

// 辅助函数：以 node 为起点，往下走，有多少条路径和 = target
int dfs(struct TreeNode* node, long long target) {
    if (!node) return 0;  // 空节点，0条
    
    int count = 0;
    // 当前节点的值 正好等于剩余目标 → 找到一条路径
    if (node->val == target) {
        count++;
    }
    // 继续往下走：target 减去当前节点值
    count += dfs(node->left, target - node->val);
    count += dfs(node->right, target - node->val);
    
    return count;
}

// 主函数：遍历每个节点，把每个节点都当作起点，统计总数
int pathSum(struct TreeNode* root, int targetSum) {
    if (!root) return 0;
    
    // 答案 = 以root为起点的数量 + 左子树所有答案 + 右子树所有答案
    int ans = dfs(root, targetSum)          // 当前节点当起点
            + pathSum(root->left, targetSum) // 递归左子树
            + pathSum(root->right, targetSum); // 递归右子树
    
    return ans;
}