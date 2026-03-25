/*
 * 文件名：08_scope_lifetime.c
 * 学习目标：
 * 1. 理解局部变量和全局变量的区别
 * 2. 理解作用域和生命周期
 *
 * 核心知识点：
 * - 作用域：变量在代码中“哪里能访问”
 * - 生命周期：变量在程序运行时“活多久”
 * - 局部变量通常在函数或代码块内有效
 * - 全局变量通常在整个文件中可见（或更广，视链接属性而定）
 *
 * 易错点：
 * - 不要滥用全局变量，容易造成模块耦合
 * - 局部变量未初始化时值不确定
 *
 * 面试考点：
 * - 局部变量和全局变量分别存哪里？答：通常局部变量在栈区，全局变量在静态存储区
 * - 生命周期和作用域是不是一回事？答：不是
 */

#include <stdio.h>

int global_count = 100;

void show_scope(void)
{
    int local_count = 10;

    printf("函数内局部变量 local_count = %d\n", local_count);
    printf("函数内可以访问全局变量 global_count = %d\n", global_count);
}

int main(void)
{
    show_scope();

    printf("main 中访问全局变量 global_count = %d\n", global_count);

    return 0;
}
