/*
 * 文件名：34_const_pointer_cases.c
 * 学习目标：
 * 1. 区分几种常见的 const 指针写法
 * 2. 能回答“谁不能改”这类面试问题
 *
 * 核心知识点：
 * - const int *p：不能通过 p 修改它指向的值
 * - int *const p：p 自己不能改指向，但可改所指向的值
 * - const int *const p：两者都不能改
 *
 * 易错点：
 * - 从右往左、从近到远理解 const 更稳妥
 * - “指针是常量”与“指向常量的指针”要分开理解
 *
 * 面试考点：
 * - const int *p 和 int *const p 区别？
 * - 哪种情况下值不能改，哪种情况下地址不能改？
 */

#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;
    const int *p1 = &a;
    int *const p2 = &a;
    const int *const p3 = &b;

    printf("p1 指向的值当前是：%d\n", *p1);
    printf("p2 指向的值当前是：%d\n", *p2);
    printf("p3 指向的值当前是：%d\n", *p3);

    *p2 = 99;
    printf("通过 p2 修改后，a = %d\n", a);
    printf("面试记忆：看 const 修饰的是 * 左边的值，还是指针本身。\n");

    return 0;
}
