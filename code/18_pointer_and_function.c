/*
 * 文件名：18_pointer_and_function.c
 * 学习目标：
 * 1. 理解为什么函数中想修改外部变量要传地址
 * 2. 用指针实现交换两个变量
 *
 * 核心知识点：
 * - C 函数参数传递本质是值传递
 * - 传地址后，函数内部可以间接修改外部变量
 *
 * 易错点：
 * - 传值交换只会交换形参，不会影响实参
 * - 指针形参必须接收正确类型的地址
 *
 * 面试考点：
 * - C 中有没有引用传递？答：没有，本质都是值传递
 * - 为什么传指针能修改外部变量？答：因为拿到了外部变量的地址
 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 10;
    int y = 20;

    printf("交换前：x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("交换后：x = %d, y = %d\n", x, y);

    return 0;
}
