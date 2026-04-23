/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积 。

// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]
// 当前数字:         1         2         3         4
// -----------------------------------------------------
// 左侧乘积(L):      1       (1)     (1*2)   (1*2*3)  = [1,  1,  2, 6]
// 右侧乘积(R): (2*3*4)    (3*4)       (4)         1  = [24, 12, 4, 1]
// -----------------------------------------------------
// 上下相乘:        24        12         8         6

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // 1. 按照 C 语言接口要求，必须明确告诉调用者返回数组的大小
    *returnSize = numsSize;

    // 2. 动态申请结果数组的内存
    int *ans = (int*)malloc(sizeof(int) * numsSize);

    // 3. 正向遍历：计算左侧乘积
    // 第一个元素左边没有数字，所以初始为 1（这一步你忘了写，非常重要）
    ans[0] = 1; 
    for (int left = 1; left < numsSize; left++) {
        // 当前位置的左侧乘积 = 前一个位置的左侧乘积 * 前一个位置的值
        ans[left] = ans[left - 1] * nums[left - 1];
    }

    // 4. 逆向遍历：计算右侧乘积，并直接盖在 ans 数组上
    int R = 1; // R 充当右侧乘积的“滚动累乘器”
    for (int right = numsSize - 1; right >= 0; right--) {
        // ans[right] 原本存着“左侧乘积”，现在乘上 R (右侧乘积)，就是最终结果
        ans[right] = ans[right] * R;
        
        // 更新滚动变量 R，把当前的 nums[right] 乘进去，供下一个位置（更左边的位置）使用
        R = R * nums[right];
    }

    // 5. 返回最终的结果数组
    return ans;
}

// int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//     *returnSize = 0;
//     int *ans = (int *)malloc(sizeof(int) * numsSize);
//     ans[0] = 1;// 第一个元素没有左乘积

//     for (int left = 1; left < numsSize; left ++) {
//         // 左乘积
//         ans[left] = ans[left - 1] * nums[left - 1];
//     }

//     int R = 1;
//     for (int right = numsSize - 1; right >= 0; right --) {
//         // 右乘积
//         ans[right] = ans[right] * R;

//         R = R * ans[right];
//     }

//     return ans;
// }