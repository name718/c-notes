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

/* 定义堆结构 */
typedef struct {
    int *heap;      // 堆数组
    int size;       // 当前堆大小
    int capacity;   // 堆容量（即 k）
} KthLargest;

// 末尾插入元素 向上移动
void heapUp(int* heap, int idx){
    while(idx > 0) {
        int parent = (idx - 1) / 2;
        // 符合小根堆的规则不处理
        if (heap[parent] <= heap[idx]) {
            break;
        }
        // 不符合需要上移交换
        int temp = heap[parent];
        heap[parent] = heap[idx];
        heap[idx] = temp;
        idx = parent;
    }
}

// 堆顶替换元素，调整堆
void heapDown(int* heap,int size, int idx){
    while(idx < size) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int smallest = idx;

        if (left < size && heap[smallest] > heap[left]) {
            smallest = left;
        }

        if (right < size && heap[smallest] > heap[right]){
            smallest = right;
        }

        if (smallest == idx) {
            break;
        }

        int temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;
        idx = smallest;
    }
}

void heapPush(KthLargest* obj, int val){
    if (obj->size < obj->capacity) {
        obj->heap[obj->size] = val;
        obj->size ++;
        // 向上调整
        heapUp(obj->heap,obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        // 替换堆顶元素，下移
        heapDown(obj->heap,obj->size, 0);
    }

}

/* 创建 KthLargest 对象 */
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    if (obj == NULL) {
        return NULL;
    }

    obj->heap = (int*)malloc(k * sizeof(int));
    if (obj->heap==NULL) {
        free(obj);
        return NULL;
    }

    obj->capacity = k;
    obj->size = 0;

    for (int i = 0; i < numsSize; i ++) {
        heapPush(obj,nums[i]);
    }

    return obj;
}

int heapTop(KthLargest* obj){
    if (obj->size == 0) {
        return 0;
    }
    return obj->heap[0];
}

/* 添加元素并返回第 K 大元素 */
int kthLargestAdd(KthLargest* obj, int val) {
    heapPush(obj, val);
    return heapTop(obj);
}

/* 释放内存 */
void kthLargestFree(KthLargest* obj) {
    if (obj != NULL) {
        if (obj->heap != NULL) {
            free(obj->heap);
        }
        free(obj);
    }
}

#ifndef LEETCODE_SUBMISSION
int main(void) {
    // 测试用例1
    printf("===== 测试用例1 =====\n");
    int nums[] = {4, 5, 8, 2};
    int k = 3;
    KthLargest* obj = kthLargestCreate(k, nums, 4);
    
    printf("add(3): %d (期望: 4)\n", kthLargestAdd(obj, 3));
    printf("add(5): %d (期望: 5)\n", kthLargestAdd(obj, 5));
    printf("add(10): %d (期望: 5)\n", kthLargestAdd(obj, 10));
    printf("add(9): %d (期望: 8)\n", kthLargestAdd(obj, 9));
    printf("add(4): %d (期望: 8)\n", kthLargestAdd(obj, 4));
    
    kthLargestFree(obj);
    
    // 测试用例2
    printf("\n===== 测试用例2 =====\n");
    int nums2[] = {0};
    k = 2;
    obj = kthLargestCreate(k, nums2, 1);
    
    printf("add(-1): %d (期望: -1)\n", kthLargestAdd(obj, -1));
    printf("add(1): %d (期望: 0)\n", kthLargestAdd(obj, 1));
    printf("add(-2): %d (期望: 0)\n", kthLargestAdd(obj, -2));
    printf("add(-4): %d (期望: 0)\n", kthLargestAdd(obj, -4));
    printf("add(3): %d (期望: 1)\n", kthLargestAdd(obj, 3));
    
    kthLargestFree(obj);
    
    // 测试用例3
    printf("\n===== 测试用例3 =====\n");
    int nums3[] = {};
    k = 1;
    obj = kthLargestCreate(k, nums3, 0);
    
    printf("add(-3): %d (期望: -3)\n", kthLargestAdd(obj, -3));
    printf("add(-2): %d (期望: -2)\n", kthLargestAdd(obj, -2));
    printf("add(-4): %d (期望: -2)\n", kthLargestAdd(obj, -4));
    printf("add(0): %d (期望: 0)\n", kthLargestAdd(obj, 0));
    printf("add(4): %d (期望: 4)\n", kthLargestAdd(obj, 4));
    
    kthLargestFree(obj);
    
    return 0;
}
#endif