/*
 * 文件名：12_arrays_basic.c
 * 学习目标：
 * 1. 学会定义和初始化一维数组
 * 2. 掌握数组遍历方式
 *
 * 核心知识点：
 * - 数组是一组相同类型元素的连续存储
 * - 下标从 0 开始
 * - 可以用 sizeof 计算元素个数
 *
 * 易错点：
 * - 数组下标越界是高频错误
 * - 数组名不是普通变量，不能整体赋值
 *
 * 面试考点：
 * - 数组名表示什么？答：多数表达式中会退化为首元素地址
 * - 如何计算数组长度？答：sizeof(arr) / sizeof(arr[0])
 */

#include <stdio.h>

int main(void)
{
    int scores[] = {88, 92, 76, 95, 81};
    int i = 0;
    int count = (int)(sizeof(scores) / sizeof(scores[0]));

    printf("数组元素个数：%d\n", count);

    for (i = 0; i < count; i++)
    {
        printf("scores[%d] = %d\n", i, scores[i]);
    }

    return 0;
}
