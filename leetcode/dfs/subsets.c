#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 深度优先搜索回溯函数
// nums: 原数组  numsSize: 数组长度
// res: 结果集  path: 临时存储当前子集
// depth: 当前子集长度  start: 遍历起始位置(去重关键)
// returnSize: 结果集大小  returnColumnSizes: 每个子集的长度
void dfs(int* nums, int numsSize, int** res, int* path, int depth, int start,
         int* returnSize, int** returnColumnSizes) {
    // 1. 每一层递归都要保存当前子集（空集也需要保存）
    // 为当前子集分配内存
    res[*returnSize] = (int*)malloc(depth * sizeof(int));
    // 复制临时路径到结果集
    memcpy(res[*returnSize], path, depth * sizeof(int));
    // 记录当前子集的长度
    (*returnColumnSizes)[*returnSize] = depth;
    // 结果集计数+1
    (*returnSize)++;

    // 2. 遍历选择下一个元素（从start开始，避免重复子集）
    for (int i = start; i < numsSize; i++) {
        // 将当前元素加入子集
        path[depth] = nums[i];
        // 递归：下一层，深度+1，起始位置+1（不回头）
        dfs(nums, numsSize, res, path, depth + 1, i + 1, returnSize, returnColumnSizes);
        // 回溯：无需手动回退，下一次循环会覆盖path[depth]
    }
}

// 主函数：生成所有子集
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 幂集总数：n个元素的子集数量 = 2^n
    int total = 1 << numsSize;  // 等价于 2^numsSize
    *returnSize = 0;            // 初始化结果集大小为0

    // 分配结果集内存（总共有total个子集）
    int** res = (int**)malloc(total * sizeof(int*));
    // 分配「每个子集长度」的内存
    *returnColumnSizes = (int*)malloc(total * sizeof(int));
    // 分配临时路径内存（最大子集长度为numsSize）
    int* path = (int*)malloc(numsSize * sizeof(int));

    // 开始DFS：初始深度0，起始位置0
    dfs(nums, numsSize, res, path, 0, 0, returnSize, returnColumnSizes);

    // 释放临时路径内存
    free(path);
    return res;
}