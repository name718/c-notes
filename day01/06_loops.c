/*
 * 文件名：06_loops.c
 * 学习目标：
 * 1. 掌握 for、while、do...while 三种循环
 * 2. 理解 break 和 continue 在循环中的作用
 *
 * 核心知识点：
 * - for：已知循环次数时常用
 * - while：先判断条件，再执行循环体
 * - do...while：先执行一次，再判断条件
 *
 * 易错点：
 * - 循环变量忘记变化，容易死循环
 * - continue 是跳过本轮，不是结束整个循环
 *
 * 面试考点：
 * - do...while 和 while 的区别？答：前者至少执行一次
 * - break 与 continue 的区别？答：一个终止循环，一个跳过当前轮
 */

#include <stdio.h>

int main(void)
{
    int i = 0;

    printf("for 循环：");
    for (i = 1; i <= 5; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    printf("while 循环：");
    i = 1;
    while (i <= 5)
    {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    printf("do...while 循环：");
    i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= 5);
    printf("\n");

    return 0;
}
