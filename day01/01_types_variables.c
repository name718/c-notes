/*
 * 文件名：01_types_variables.c
 * 学习目标：
 * 1. 理解 C 中常见基本类型
 * 2. 学会定义变量、常量，并使用 sizeof
 *
 * 核心知识点：
 * - 常见类型：char、int、float、double
 * - 变量定义与初始化
 * - const 修饰只读变量
 * - sizeof 用于查看类型或变量占用的字节数
 *
 * 易错点：
 * - 不要想当然认为 int 一定是 4 字节，标准没有强制写死，只是常见实现如此
 * - sizeof 的结果类型是 size_t，打印时常用 %zu
 *
 * 面试考点：
 * - 基本类型大小是否固定？答：和编译器、平台有关
 * - float 和 double 区别？答：精度和存储空间不同
 * - const 是“真正常量”还是“只读变量”？答：更准确地说是只读对象
 */

#include <stdio.h>

int main(void)
{
    char grade = 'A';
    int age = 20;
    float height = 175.5f;
    double weight = 68.75;
    const int days_per_week = 7;

    printf("grade = %c\n", grade);
    printf("age = %d\n", age);
    printf("height = %.1f\n", height);
    printf("weight = %.2lf\n", weight);
    printf("days_per_week = %d\n", days_per_week);

    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(float) = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));

    return 0;
}
