#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：155
 * 题目：Min Stack
 * 地址：https://leetcode.com/problems/min-stack/
 */

/*
 * 题目：最小栈
 * 难度：中等
 * 练习点：栈设计、辅助栈、O(1) 查询最小值
 *
 * 题意（改写）：
 * 设计支持 push、pop、top、getMin 的栈，且 getMin 需要 O(1) 时间。
 *
 * 算法描述：
 * 1. 主栈保存所有元素。
 * 2. 辅助栈同步保存当前最小值。
 * 3. 入栈和出栈时同步维护辅助栈。
 */

typedef struct {
    int placeholder;
} MinStack;

MinStack *minStackCreate(void)
{
    /* TODO: 在这里完成具体实现 */
    return NULL;
}

void minStackPush(MinStack *obj, int val)
{
    (void)obj;
    (void)val;

    /* TODO: 在这里完成具体实现 */
}

void minStackPop(MinStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}

int minStackTop(MinStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

int minStackGetMin(MinStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

void minStackFree(MinStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}
