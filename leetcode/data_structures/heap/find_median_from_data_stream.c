#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：295
 * 题目：Find Median from Data Stream
 * 地址：https://leetcode.com/problems/find-median-from-data-stream/
 */

/*
 * 题目：数据流的中位数
 * 难度：困难
 * 练习点：双堆、数据流、平衡维护
 *
 * 题意（改写）：
 * 设计数据结构支持 addNum 与 findMedian 操作，动态返回当前中位数。
 *
 * 算法描述：
 * 1. 使用最大堆保存较小一半，最小堆保存较大一半。
 * 2. 插入后调整两个堆的大小差不超过 1。
 * 3. 根据堆大小关系计算中位数。
 */

typedef struct {
    int placeholder;
} MedianFinder;

MedianFinder *medianFinderCreate(void)
{
    /* TODO: 在这里完成具体实现 */
    return NULL;
}

void medianFinderAddNum(MedianFinder *obj, int num)
{
    (void)obj;
    (void)num;

    /* TODO: 在这里完成具体实现 */
}

double medianFinderFindMedian(MedianFinder *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return 0.0;
}

void medianFinderFree(MedianFinder *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}
