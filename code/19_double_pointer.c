/*
 * 文件名：19_double_pointer.c
 * 学习目标：
 * 1. 理解二级指针的含义
 * 2. 认识二级指针的基本使用场景
 *
 * 核心知识点：
 * - 一级指针保存变量地址
 * - 二级指针保存一级指针的地址
 *
 * 易错点：
 * - *p 和 **p 含义不同，要分清层级
 * - 二级指针的类型必须匹配
 *
 * 面试考点：
 * - 什么场景会用到二级指针？答：修改一级指针本身、处理指针数组、argv 等
 * - char **argv 是什么？答：指向字符指针的指针，常用于命令行参数
 */

#include <stdio.h>

int main(void)
{
    int value = 42;
    int *p = &value;
    int **pp = &p;

    printf("value = %d\n", value);
    printf("*p = %d\n", *p);
    printf("**pp = %d\n", **pp);

    return 0;
}
