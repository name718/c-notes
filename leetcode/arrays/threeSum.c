#include <stdlib.h>

// https://leetcode.cn/problems/3sum/?envType=study-plan-v2&envId=top-100-liked
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
// 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
// 请你返回所有和为 0 且不重复的三元组。

int comp(const void *a, const void *b) {
    return *(const int*)a - *(const int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), comp);

    int cap = 128;
    int **res = (int **)malloc(cap * sizeof(int *));
    *returnColumnSizes = (int *)malloc(cap * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        // 去重：跳过相同的第一个数
        if (i > 0 && nums[i] == nums[i-1]) continue;
        
        // 优化：如果当前最小的数都大于0，后面不可能有解
        if (nums[i] > 0) break;
        
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // 动态扩容
                if (*returnSize >= cap) {
                    cap *= 2;
                    res = (int **)realloc(res, cap * sizeof(int *));
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, cap * sizeof(int));
                }
                
                // 存储结果
                res[*returnSize] = (int *)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[left];
                res[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                // 跳过重复的left和right
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                
                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    return res;
}