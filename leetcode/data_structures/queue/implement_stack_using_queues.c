#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：225
 * 题目：Implement Stack using Queues
 * 地址：https://leetcode.com/problems/implement-stack-using-queues/
 */

/*
 * 题目：用队列实现栈
 * 难度：简单
 * 练习点：队列模拟、结构设计、操作重排
 *
 * 题意（改写）：
 * 仅用队列实现栈的基本操作：push、pop、top、empty。
 *
 * 算法描述：
 * 1. 可使用一个队列：push 后把前面元素轮转到尾部。
 * 2. 这样队头始终是最新入栈元素。
 * 3. pop/top 直接访问队头即可。
 */

typedef struct {
    int placeholder;
} MyStack;

MyStack *myStackCreate(void)
{
    /* TODO: 在这里完成具体实现 */
    return NULL;
}

void myStackPush(MyStack *obj, int x)
{
    (void)obj;
    (void)x;

    /* TODO: 在这里完成具体实现 */
}

int myStackPop(MyStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

int myStackTop(MyStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

bool myStackEmpty(MyStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
    return true;
}

void myStackFree(MyStack *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}
