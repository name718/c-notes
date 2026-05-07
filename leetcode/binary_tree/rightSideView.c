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
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* ans = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int head = 0;
    int tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        
        // 遍历当前层
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* cur = queue[head++];
            
            // 左右孩子入队
            if (cur->left)
                queue[tail++] = cur->left;
            if (cur->right)
                queue[tail++] = cur->right;
            
            // 当前层最后一个 → 右视图
            if (i == levelSize - 1) {
                ans[(*returnSize)++] = cur->val;
            }
        }
    }

    free(queue);
    return ans;
}