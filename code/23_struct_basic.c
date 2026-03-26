/*
 * 文件名：23_struct_basic.c
 * 学习目标：
 * 1. 掌握结构体的定义和使用
 * 2. 理解结构体适合表示“多个相关字段组成的对象”
 *
 * 核心知识点：
 * - struct 可以把不同类型的数据组合到一起
 * - 使用 . 访问成员，指针访问成员用 ->
 *
 * 易错点：
 * - 结构体变量和结构体类型名不是一回事
 * - 成员访问符 . 和 -> 不要混淆
 *
 * 面试考点：
 * - 什么时候使用结构体？答：描述具有多个属性的数据对象时
 * - p->name 和 (*p).name 是否等价？答：等价
 */

#include <stdio.h>

struct Student
{
    char name[20];
    int age;
    double score;
};

int main(void)
{
    struct Student stu = {"Alice", 20, 95.5};

    printf("姓名：%s\n", stu.name);
    printf("年龄：%d\n", stu.age);
    printf("成绩：%.1lf\n", stu.score);

    return 0;
}
