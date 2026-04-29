// #include <stdlib.h>
// #include <string.h>

// int subarraySum(int* nums, int numsSize, int k) {
//     // 使用哈希表存储前缀和出现的次数
//     // 由于前缀和可能为负数，这里用一个简单的数组来模拟（如果数字范围很大，需要用真正的哈希表）
//     // 但为了简化，这里先用一个简单的方案：遍历所有子数组（O(n²)）
    
//     // 方案1：暴力法（适用于小数据）
//     int res = 0;
//     for (int left = 0; left < numsSize; left++) {
//         int sum = 0;
//         for (int right = left; right < numsSize; right++) {
//             sum += nums[right];
//             if (sum == k) {
//                 res++;
//             }
//         }
//     }
//     return res;
// }

// #include <stdlib.h>
// #include <string.h>

// // 简单的哈希表实现（假设前缀和范围在 -1e6 到 1e6 之间）
// #define HASH_SIZE 2000001
// #define OFFSET 1000000  // 将负数偏移到正数索引

// int subarraySum(int* nums, int numsSize, int k) {
//     // 使用数组模拟哈希表（如果需要处理更大的范围，可以用真正的哈希表）
//     int* hash = (int*)calloc(HASH_SIZE, sizeof(int));
    
//     int res = 0;
//     int prefixSum = 0;
    
//     // 初始化：前缀和为0出现1次
//     hash[0 + OFFSET] = 1;
    
//     for (int i = 0; i < numsSize; i++) {
//         prefixSum += nums[i];
        
//         // 查找 prefixSum - k 是否出现过
//         int target = prefixSum - k;
//         if (target + OFFSET >= 0 && target + OFFSET < HASH_SIZE) {
//             res += hash[target + OFFSET];
//         }
        
//         // 记录当前前缀和
//         hash[prefixSum + OFFSET]++;
//     }
    
//     free(hash);
//     return res;
// }

#include <stdlib.h>
#include "uthash.h"  // 需要安装uthash库

struct HashNode {
    int key;
    int count;
    UT_hash_handle hh;
};

int subarraySum(int* nums, int numsSize, int k) {
    struct HashNode* hash = NULL;
    struct HashNode* node = NULL;
    
    int res = 0;
    int prefixSum = 0;
    
    // 插入初始前缀和0
    node = (struct HashNode*)malloc(sizeof(struct HashNode));
    node->key = 0;
    node->count = 1;
    HASH_ADD_INT(hash, key, node);
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        
        // 查找 prefixSum - k
        int target = prefixSum - k;
        HASH_FIND_INT(hash, &target, node);
        if (node) {
            res += node->count;
        }
        
        // 更新当前前缀和
        HASH_FIND_INT(hash, &prefixSum, node);
        if (node) {
            node->count++;
        } else {
            node = (struct HashNode*)malloc(sizeof(struct HashNode));
            node->key = prefixSum;
            node->count = 1;
            HASH_ADD_INT(hash, key, node);
        }
    }
    
    // 释放哈希表
    struct HashNode *current, *tmp;
    HASH_ITER(hh, hash, current, tmp) {
        HASH_DEL(hash, current);
        free(current);
    }
    
    return res;
}