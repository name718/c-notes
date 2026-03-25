/*
 * 文件名：33_declaration_vs_definition.c
 * 学习目标：
 * 1. 区分声明和定义
 * 2. 理解为什么会出现“重复定义”或“只有声明没有定义”
 *
 * 核心知识点：
 * - 声明：告诉编译器名字和类型
 * - 定义：真正分配实体或给出实现
 *
 * 易错点：
 * - extern int a; 常常是声明
 * - int a = 10; 是定义
 *
 * 面试考点：
 * - 函数声明和函数定义区别？
 * - 变量声明和变量定义区别？
 * - 为什么头文件里一般放声明而不是定义？
 */

#include <stdio.h>

int global_number = 10;
extern int global_number;

void show_message(void);

void show_message(void)
{
    printf("这是函数定义。\n");
}

int main(void)
{
    printf("global_number = %d\n", global_number);
    show_message();
    printf("说明：extern int global_number; 是声明，int global_number = 10; 是定义。\n");

    return 0;
}
