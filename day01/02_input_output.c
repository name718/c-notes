/*
 * 文件名：02_input_output.c
 * 学习目标：
 * 1. 掌握 printf 的基本输出格式
 * 2. 学会使用 scanf 读取输入
 *
 * 核心知识点：
 * - printf 用于格式化输出
 * - scanf 用于按指定格式读取数据
 * - scanf 读取变量时，通常要传变量地址
 *
 * 易错点：
 * - int、float、double、char 的格式控制符要区分
 * - scanf("%d", &num) 中的 & 不能少（数组名除外）
 * - scanf 遇到非法输入时可能读取失败
 *
 * 面试考点：
 * - 为什么 scanf 通常需要传地址？答：函数要把读到的数据写回变量
 * - printf 和 scanf 的返回值分别有什么意义？答：一个表示输出字符数，一个表示成功匹配项数
 */

#include <stdio.h>

int main(void)
{
    int age = 0;
    double score = 0.0;

    printf("请输入年龄和成绩，例如：18 95.5\n");

    if (scanf("%d %lf", &age, &score) != 2)
    {
        printf("输入格式错误。\n");
        return 1;
    }

    printf("你输入的年龄是：%d\n", age);
    printf("你输入的成绩是：%.2lf\n", score);

    return 0;
}
