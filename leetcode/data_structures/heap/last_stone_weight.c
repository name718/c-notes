#include <assert.h>
#include <stdio.h>

/*
 * LeetCode 题号：1046
 * 题目：Last Stone Weight
 * 地址：https://leetcode.com/problems/last-stone-weight/
 */

/*
 * 题目：最后一块石头的重量
 * 难度：简单
 * 练习点：最大堆、优先队列、模拟
 *
 * 题意（改写）：
 * 每次取出最重的两块石头碰撞，按规则放回差值，直到剩 0 或 1 块。
 * 返回最后石头重量。
 *
 * 算法描述：
 * 1. 用最大堆存储所有石头重量。
 * 2. 每轮弹出两个最大值进行碰撞。
 * 3. 若差值非 0，重新压入堆中。
 */

int lastStoneWeight(int *stones, int stonesSize)
{
    (void)stones;
    (void)stonesSize;

    /* TODO: 在这里完成具体实现 */
    return 0;
}
