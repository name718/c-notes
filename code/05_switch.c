/*
 * 文件名：05_switch.c
 * 学习目标：
 * 1. 掌握 switch-case 的基本结构
 * 2. 理解 break 的作用
 *
 * 核心知识点：
 * - switch 适合“一个值对应多个固定分支”的场景
 * - break 用于结束当前 case，避免贯穿执行
 *
 * 易错点：
 * - 忘记写 break，程序会继续执行后面的 case
 * - switch 不适合范围判断，如 score > 90
 *
 * 面试考点：
 * - switch 和 if-else 的区别？答：switch 更适合离散值匹配
 * - case 后面为什么要求常量表达式？答：编译期就要确定分支标签
 */

#include <stdio.h>

int main(void)
{
    int day = 3;

    switch (day)
    {
        case 1:
            printf("星期一\n");
            break;
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
        case 7:
            printf("周末\n");
            break;
        default:
            printf("输入的日期不合法\n");
            break;
    }

    return 0;
}
