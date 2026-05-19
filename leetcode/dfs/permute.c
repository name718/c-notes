/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

// 回溯函数参数
void backtrack(int *nums, int numsSize, int **res, int *path, int depth, int *used, int *returnSize)
{
    // 终止条件：路径深度等于数组长度，说明找到一个排列
    if (depth == numsSize)
    {
        // 把当前路径复制到结果数组
        res[*returnSize] = (int *)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++)
        {
            res[*returnSize][i] = path[i];
        }
        (*returnSize)++;
        return;
    }

    // 遍历所有数字
    for (int i = 0; i < numsSize; i++)
    {
        if (used[i])
            continue; // 已使用，跳过

        used[i] = 1;           // 标记使用
        path[depth] = nums[i]; // 加入当前路径
        backtrack(nums, numsSize, res, path, depth + 1, used, returnSize);
        used[i] = 0; // 回溯，撤销标记
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    // 全排列总数：n!
    int total = 1;
    for (int i = 2; i <= numsSize; i++)
    {
        total *= i;
    }

    // 分配结果数组
    int **res = (int **)malloc(total * sizeof(int *));
    *returnSize = 0;

    // 临时路径 + 标记数组
    int *path = (int *)malloc(numsSize * sizeof(int));
    int *used = (int *)calloc(numsSize, sizeof(int)); // 初始化为0

    // 开始回溯
    backtrack(nums, numsSize, res, path, 0, used, returnSize);

    // 设置列大小（每个排列长度都是 numsSize）
    *returnColumnSizes = (int *)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }

    // 释放临时内存
    free(path);
    free(used);

    return res;
}