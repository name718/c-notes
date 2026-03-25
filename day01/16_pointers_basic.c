/*
 * 文件名：16_pointers_basic.c
 * 学习目标：
 * 1. 理解指针变量保存的是地址
 * 2. 掌握取地址和解引用
 *
 * 核心知识点：
 * - &：取地址运算符
 * - *：定义指针时表示“指针类型”，解引用时表示“访问地址里的值”
 *
 * 易错点：
 * - 指针必须指向合法地址后才能解引用
 * - int *p 和 int* p 含义一样，只是书写风格不同
 *
 * 面试考点：
 * - 指针的本质是什么？答：保存地址的变量
 * - * 和 & 分别是什么作用？答：一个取值，一个取地址
 */

#include <stdio.h>

int main(void)
{
    int num = 100;
    int *ptr = &num;

    printf("num 的值：%d\n", num);
    printf("num 的地址：%p\n", (void *)&num);
    printf("ptr 保存的地址：%p\n", (void *)ptr);
    printf("通过 *ptr 访问的值：%d\n", *ptr);

    return 0;
}
