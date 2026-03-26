#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * 题目：两数之和
 * 难度：简单
 * 练习点：数组、双重循环、指针、动态内存、返回数组
 *
 * 题意（改写）：
 * 给定一个整数数组 nums 和一个目标值 target，
 * 找出两个不同下标 i 和 j，使得 nums[i] + nums[j] == target。
 * 题目保证恰好存在一个答案。
 *
 * 你需要返回一个长度为 2 的动态数组，
 * 并通过 returnSize 告诉调用者返回数组的长度。
 *
 * 示例：
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 */

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    (void)nums;
    (void)numsSize;
    (void)target;

    if (returnSize != NULL) {
        *returnSize = 0;
    }

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

static int is_valid_answer(const int *answer, int returnSize, int first, int second)
{
    if (answer == NULL || returnSize != 2) {
        return 0;
    }

    return (answer[0] == first && answer[1] == second) ||
           (answer[0] == second && answer[1] == first);
}

static void run_tests(void)
{
    {
        int nums[] = {2, 7, 11, 15};
        int returnSize = 0;
        int *answer = twoSum(nums, 4, 9, &returnSize);

        assert(is_valid_answer(answer, returnSize, 0, 1));
        free(answer);
    }

    {
        int nums[] = {3, 2, 4};
        int returnSize = 0;
        int *answer = twoSum(nums, 3, 6, &returnSize);

        assert(is_valid_answer(answer, returnSize, 1, 2));
        free(answer);
    }

    {
        int nums[] = {3, 3};
        int returnSize = 0;
        int *answer = twoSum(nums, 2, 6, &returnSize);

        assert(is_valid_answer(answer, returnSize, 0, 1));
        free(answer);
    }
}

#ifdef RUN_TESTS
int main(void)
{
    run_tests();
    printf("two_sum.c: all tests passed\n");
    return 0;
}
#endif
