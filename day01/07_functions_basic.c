/*
 * 文件名：07_functions_basic.c
 * 学习目标：
 * 1. 理解函数声明、定义、调用
 * 2. 掌握参数和返回值的基本用法
 *
 * 核心知识点：
 * - 函数声明告诉编译器“函数长什么样”
 * - 函数定义给出函数的具体实现
 * - 参数用于接收外部传入的数据
 *
 * 易错点：
 * - 函数先调用后定义时，通常应先声明
 * - 返回值类型要和实际返回数据匹配
 *
 * 面试考点：
 * - 声明和定义的区别？答：声明描述接口，定义分配实体并给出实现
 * - C 语言参数传递本质是什么？答：值传递
 */

#include <stdio.h>

// 函数声明（函数原型）
int add(int a, int b);
int add(int a, int b);
// int add(int a, int b, int c); // 错误：函数重载在 C 语言中不支持

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int result = add(10, 20);

    printf("10 + 20 = %d\n", result);

    return 0;
}
