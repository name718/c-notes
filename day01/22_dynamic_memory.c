/*
 * 文件名：22_dynamic_memory.c
 * 学习目标：
 * 1. 掌握 malloc、calloc、realloc、free 的基本用法
 * 2. 理解动态内存管理的基本流程
 *
 * 核心知识点：
 * - malloc：申请一块未初始化内存
 * - calloc：申请并清零
 * - realloc：调整已申请内存大小
 * - free：释放内存
 *
 * 易错点：
 * - 申请后要判空
 * - 释放后不要继续使用原地址
 * - realloc 失败时原指针仍然有效
 *
 * 面试考点：
 * - malloc 和 calloc 区别？答：一个不清零，一个清零
 * - 为什么会内存泄漏？答：申请后没有正确释放
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 0;
    int *arr = (int *)calloc(3, sizeof(int));
    int *new_arr = NULL;

    if (arr == NULL)
    {
        printf("calloc 申请失败。\n");
        return 1;
    }

    for (i = 0; i < 3; i++)
    {
        arr[i] = (i + 1) * 10;
    }

    new_arr = (int *)realloc(arr, 5 * sizeof(int));
    if (new_arr == NULL)
    {
        free(arr);
        printf("realloc 失败。\n");
        return 1;
    }

    arr = new_arr;
    arr[3] = 40;
    arr[4] = 50;

    for (i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}
