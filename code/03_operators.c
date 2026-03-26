/*
 * 文件名：03_operators.c
 * 学习目标：
 * 1. 理解常见运算符的使用方式
 * 2. 认识 ++i 与 i++ 的区别
 *
 * 核心知识点：
 * - 算术运算符：+ - * / %
 * - 关系运算符：> < >= <= == !=
 * - 逻辑运算符：&& || !
 * - 自增自减：++ --
 *
 * 易错点：
 * - 整数相除会丢失小数部分
 * - == 是比较，= 是赋值
 * - 复杂表达式里不要滥用 ++，可读性差且容易出错
 *
 * 面试考点：
 * - i++ 和 ++i 的区别？答：表达式求值时返回值不同
 * - && 和 || 为什么叫短路运算？答：前半部分已能决定结果时，后半部分不再计算
 */

#include <stdio.h>

int main(void)
{
    int a = 7;
    int b = 3;
    int x = 5;
    int y = 5;

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);

    printf("a > b 的结果：%d\n", a > b);
    printf("(a > b) && (b > 0) 的结果：%d\n", (a > b) && (b > 0));

    printf("x 初始值：%d\n", x);
    printf("x++ 的表达式值：%d\n", x++);
    printf("x 现在变成：%d\n", x);

    printf("y 初始值：%d\n", y);
    printf("++y 的表达式值：%d\n", ++y);
    printf("y 现在变成：%d\n", y);

    return 0;
}
