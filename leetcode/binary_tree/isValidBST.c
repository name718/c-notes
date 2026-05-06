#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> // 需要用到 LLONG_MIN 和 LLONG_MAX

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 辅助函数，携带了上下边界
bool isValidBSTHelper(struct TreeNode* node, long long min_val, long long max_val) {
    // 1. 空节点是合法的 BST
    if (node == NULL) {
        return true;
    }
    
    // 2. 判断当前节点是否越界
    // 当前节点的值必须严格大于下界，且严格小于上界
    if (node->val <= min_val || node->val >= max_val) {
        return false;
    }
    
    // 3. 递归检查左右子树
    // 往左走：最大值不能超过当前节点的值 (更新 max_val)
    // 往右走：最小值必须大于当前节点的值 (更新 min_val)
    return isValidBSTHelper(node->left, min_val, node->val) && 
           isValidBSTHelper(node->right, node->val, max_val);
}

bool isValidBST(struct TreeNode* root) {
    // 初始时，根节点的值可以是任何整数，所以区间设为 long long 的极值
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}