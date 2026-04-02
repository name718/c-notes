#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：215
 * 题目：Kth Largest Element in an Array
 * 地址：https://leetcode.cn/problems/kth-largest-element-in-an-array/
 */

/*
 * 题目：数组中的第 K 个最大元素
 * 难度：中等
 * 练习点：快速选择、堆、分区思想
 *
 * 题意（改写）：
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 注意：这里找的是排序后第 k 大，不是第 k 个不同元素。
 *
 * 算法描述：
 * 1. 快速选择：每次分区后只递归目标区间，平均 O(n)。
 * 2. 或最小堆：维护大小为 k 的最小堆，遍历结束堆顶即答案。
 * 3. 处理边界：k 的取值满足 1 <= k <= numsSize。
 */

/* 定义堆结构 */
typedef struct {
    int *heap;      // 堆数组
    int size;       // 当前堆大小
    int capacity;   // 堆容量（即 k）
} KthLargest;

void heapUp(int *heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] > heap[idx]) {
            int temp = heap[idx];
            heap[idx] = heap[parent];
            heap[parent] = temp;
            idx = parent;
        } else {
            break;
        }
    }
}

void heapDown(int *heap, int size, int idx) {
    while (idx < size) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int minIdx = idx;

        if (left < size && heap[minIdx] > heap[left]) {
            minIdx = left;
        }
        if (right < size && heap[minIdx] > heap[right]) {
            minIdx = right;
        }

        if (minIdx == idx) {
            break;
        }

        int temp = heap[idx];
        heap[idx] = heap[minIdx];
        heap[minIdx] = temp;
        idx = minIdx;
    }
}

void heapPush(KthLargest *obj, int num) {
    if (obj->size < obj->capacity) {
        // 堆未满，直接插入末尾
        obj->heap[obj->size] = num;
        obj->size++;
        heapUp(obj->heap, obj->size - 1);
    } else {
        // 堆已满，如果新数大于堆顶（最小值），则替换
        if (num > obj->heap[0]) {
            obj->heap[0] = num;
            heapDown(obj->heap, obj->size, 0);
        }
    }
}

int heapTop(KthLargest *obj) {
    if (obj->size == 0) {
        return 0;
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest *obj) {
    if (obj != NULL) {
        if (obj->heap != NULL) {
            free(obj->heap);
        }
        free(obj);
    }
}

int findKthLargest(int *nums, int numsSize, int k)
{
    (void)nums;
    (void)numsSize;
    (void)k;

    /* TODO: 在这里完成具体实现 */
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    if (obj == NULL) {
        return -1;
    }
    
    obj->heap = (int *)malloc(k * sizeof(int));
    if (obj->heap == NULL) {
        free(obj);
        return -1;
    }
    
    obj->capacity = k;
    obj->size = 0;

    for (int i = 0; i < numsSize; i++) {
        heapPush(obj, nums[i]);
    }

    int answer = heapTop(obj);
    kthLargestFree(obj);

    return answer;
}

#ifndef LEETCODE_SUBMISSION
int main(void)
{
    printf("kth_largest_element_in_an_array.c template ready\n");
    return 0;
}
#endif
