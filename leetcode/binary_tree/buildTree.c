#include <stdio.h>
#include <stdlib.h>

// 二叉树节点定义
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 辅助函数：在中序数组中找到目标值的下标
int findIndex(int* inorder, int inStart, int inEnd, int val) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1; // 题目保证输入有效，不会执行到这里
}

// 递归构建二叉树
// preStart: 前序数组起始下标
// inStart: 中序数组起始下标
// inEnd: 中序数组结束下标
struct TreeNode* build(int* preorder, int preStart, int* inorder, int inStart, int inEnd) {
    // 递归终止条件：区间为空，返回NULL
    if (inStart > inEnd) {
        return NULL;
    }
    
    // 1. 前序遍历第一个元素 = 根节点
    int rootVal = preorder[preStart];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;
    
    // 2. 在中序数组中找到根节点的位置
    int rootIndex = findIndex(inorder, inStart, inEnd, rootVal);
    // 左子树的节点个数
    int leftSize = rootIndex - inStart;
    
    // 3. 递归构建左子树
    // 前序：根节点后 leftSize 个元素是左子树
    // 中序：根节点左侧所有元素是左子树
    root->left = build(preorder, preStart + 1, inorder, inStart, rootIndex - 1);
    
    // 4. 递归构建右子树
    // 前序：跳过根+左子树，剩下的是右子树
    // 中序：根节点右侧所有元素是右子树
    root->right = build(preorder, preStart + leftSize + 1, inorder, rootIndex + 1, inEnd);
    
    return root;
}

// 主函数（题目要求的接口）
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    // 调用递归函数，初始化起始/结束下标
    return build(preorder, 0, inorder, 0, inorderSize - 1);
}

// ------------------- 测试代码 -------------------
// 层序遍历打印二叉树（验证结果）
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        printf("%d ", node->val);
        if (node->left != NULL) queue[rear++] = node->left;
        if (node->right != NULL) queue[rear++] = node->right;
    }
}

int main() {
    // 测试用例：前序 [3,9,20,15,7]，中序 [9,3,15,20,7]
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};
    int preSize = sizeof(preorder) / sizeof(preorder[0]);
    int inSize = sizeof(inorder) / sizeof(inorder[0]);
    
    struct TreeNode* root = buildTree(preorder, preSize, inorder, inSize);
    printf("构造后的二叉树层序遍历：");
    levelOrder(root); // 输出：3 9 20 15 7
    return 0;
}