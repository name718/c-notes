#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：703
 * 题目：Kth Largest Element in a Stream
 * 地址：https://leetcode.cn/problems/kth-largest-element-in-a-stream/
 */

/*
 * 题目：数据流中的第 K 大元素
 * 难度：简单
 * 练习点：最小堆、数据流、结构体设计
 *
 * 题意（改写）：
 * 设计一个类 KthLargest，支持初始化和 add(val) 操作，
 * 每次 add 后返回当前数据流中的第 k 大元素。
 *
 * 算法描述：
 * 1. 内部维护一个大小不超过 k 的最小堆。
 * 2. 新元素加入后，若堆大小超过 k 则弹出堆顶。
 * 3. 堆顶元素始终表示当前第 k 大。
 */

typedef struct {
    int placeholder;
} KthLargest;

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
    (void)k;
    (void)nums;
    (void)numsSize;

    /* TODO: 在这里完成具体实现 */
    return NULL;
}

int kthLargestAdd(KthLargest *obj, int val)
{
    (void)obj;
    (void)val;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

void kthLargestFree(KthLargest *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("kth_largest_element_in_a_stream.c template ready\n");
    return 0;
}
#endif
