/*
 * 文件名：30_macro_pitfalls.c
 * 学习目标：
 * 1. 理解带参宏的常见风险
 * 2. 学会用括号降低宏替换带来的问题
 *
 * 核心知识点：
 * - 宏是文本替换，不是函数调用
 * - 宏参数和整体表达式通常都要加括号
 *
 * 易错点：
 * - 宏参数不加括号，运算优先级可能出错
 * - 带副作用的实参传给宏可能被重复求值
 *
 * 面试考点：
 * - 宏和函数区别？答：宏无类型检查、可能更快、但更危险
 * - 为什么说宏容易出 bug？答：因为只是替换，不理解表达式语义
 */

#include <stdio.h>

#define SQUARE_BAD(x) x * x
#define SQUARE_GOOD(x) ((x) * (x))

int main(void)
{
    int result_bad = SQUARE_BAD(1 + 2);
    int result_good = SQUARE_GOOD(1 + 2);

    printf("SQUARE_BAD(1 + 2) = %d\n", result_bad);
    printf("SQUARE_GOOD(1 + 2) = %d\n", result_good);
    printf("说明：坏宏展开后相当于 1 + 2 * 1 + 2。\n");

    return 0;
}
