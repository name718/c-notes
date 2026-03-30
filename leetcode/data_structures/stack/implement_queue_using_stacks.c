#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：232
 * 题目：Implement Queue using Stacks
 * 地址：https://leetcode.com/problems/implement-queue-using-stacks/
 */

/*
 * 题目：用栈实现队列
 * 难度：简单
 * 练习点：双栈、队列模拟、摊还复杂度
 *
 * 题意（改写）：
 * 仅用两个栈实现队列的基本操作：push、pop、peek、empty。
 *
 * 算法描述：
 * 1. 一个输入栈负责入队。
 * 2. 一个输出栈负责出队。
 * 3. 当输出栈为空时，将输入栈全部转移到输出栈。
 */

typedef struct {
    int placeholder;
} MyQueue;

MyQueue *myQueueCreate(void)
{
    /* TODO: 在这里完成具体实现 */
    return NULL;
}

void myQueuePush(MyQueue *obj, int x)
{
    (void)obj;
    (void)x;

    /* TODO: 在这里完成具体实现 */
}

int myQueuePop(MyQueue *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

int myQueuePeek(MyQueue *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

bool myQueueEmpty(MyQueue *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return true;
}

void myQueueFree(MyQueue *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}
