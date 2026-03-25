/*
 * 文件名：04_branch.c
 * 学习目标：
 * 1. 学会使用 if、else if、else
 * 2. 理解条件表达式的真假判断
 *
 * 核心知识点：
 * - if 适合进行条件分支判断
 * - 在 C 中，0 表示假，非 0 表示真
 *
 * 易错点：
 * - if (score = 60) 是赋值，不是比较
 * - 多分支判断时要注意顺序
 *
 * 面试考点：
 * - C 里 true/false 的本质是什么？答：0 为假，非 0 为真
 * - 为什么 if 条件里写赋值是危险的？答：容易把比较写成赋值，造成逻辑错误
 */

#include <stdio.h>

int main(void)
{
    int score = 82;

    if (score >= 90)
    {
        printf("等级：A\n");
    }
    else if (score >= 80)
    {
        printf("等级：B\n");
    }
    else if (score >= 60)
    {
        printf("等级：C\n");
    }
    else
    {
        printf("等级：D\n");
    }

    return 0;
}
