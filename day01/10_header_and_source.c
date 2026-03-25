/*
 * 文件名：10_header_and_source.c
 * 学习目标：
 * 1. 理解 .h 和 .c 的职责分工
 * 2. 认识“声明放头文件、定义放源文件”的常见组织方式
 *
 * 核心知识点：
 * - .h 文件常放：宏、类型定义、函数声明
 * - .c 文件常放：函数定义、内部实现细节
 * - 模块化可以提高复用性和可维护性
 *
 * 易错点：
 * - 不要在头文件里随意定义全局变量
 * - 不要把所有实现都堆到头文件里
 *
 * 面试考点：
 * - 为什么函数声明放头文件？答：便于多个源文件共享接口
 * - 为什么定义常放源文件？答：避免重复定义，也利于隐藏实现
 *
 * 说明：
 * - 本文件为了满足“一文件一个示例”，用注释模拟真实工程写法。
 *
 * 典型结构：
 *   math_utils.h
 *     int add(int a, int b);
 *
 *   math_utils.c
 *     #include "math_utils.h"
 *     int add(int a, int b) { return a + b; }
 *
 *   main.c
 *     #include "math_utils.h"
 *     printf("%d\n", add(1, 2));
 */

#include <stdio.h>

int add_demo(int a, int b)
{
    return a + b;
}

int main(void)
{
    printf(".h 文件通常放声明，.c 文件通常放定义。\n");
    printf("这里模拟调用结果：3 + 4 = %d\n", add_demo(3, 4));

    return 0;
}
