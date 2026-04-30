/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 层序遍历
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 初始化队列，初始容量设为100
    int queue_capacity = 100;
    struct TreeNode** queue = (struct TreeNode**)malloc(queue_capacity * sizeof(struct TreeNode*));
    int queue_head = 0, queue_tail = 0;
    queue[queue_tail++] = root;

    // 初始化结果数组和列数数组，初始容量设为100
    int ans_capacity = 100;
    int** ans = (int**)malloc(ans_capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(ans_capacity * sizeof(int));

    while (queue_head < queue_tail) {
        // 队列扩容：如果tail到达容量上限，扩容为原来的2倍
        if (queue_tail >= queue_capacity) {
            queue_capacity *= 2;
            queue = (struct TreeNode**)realloc(queue, queue_capacity * sizeof(struct TreeNode*));
        }

        // 结果数组扩容：如果returnSize到达容量上限，扩容为原来的2倍
        if (*returnSize >= ans_capacity) {
            ans_capacity *= 2;
            ans = (int**)realloc(ans, ans_capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, ans_capacity * sizeof(int));
        }

        int current_level_size = queue_tail - queue_head;
        int* level = (int*)malloc(current_level_size * sizeof(int));
        
        for (int i = 0; i < current_level_size; i++) {
            struct TreeNode* node = queue[queue_head++];
            level[i] = node->val;
            
            if (node->left != NULL) {
                queue[queue_tail++] = node->left;
            }
            if (node->right != NULL) {
                queue[queue_tail++] = node->right;
            }
        }

        ans[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = current_level_size;
        (*returnSize)++;
    }

    free(queue);
    return ans;
}