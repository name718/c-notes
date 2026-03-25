/*
 * 文件名：25_union_enum_typedef.c
 * 学习目标：
 * 1. 认识联合体、枚举、typedef
 * 2. 理解它们各自的应用场景
 *
 * 核心知识点：
 * - union：多个成员共用同一块内存
 * - enum：给一组整数常量取有意义的名字
 * - typedef：给类型起别名
 *
 * 易错点：
 * - union 同一时刻通常只可靠地使用最近写入的那个成员
 * - typedef 不会创建新类型本质，只是别名
 *
 * 面试考点：
 * - struct 和 union 区别？答：一个成员各占空间，一个共享空间
 * - enum 的作用？答：提高可读性，适合表示有限状态集合
 */

#include <stdio.h>

union Number
{
    int int_value;
    float float_value;
};

enum Weekday
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY
};

typedef unsigned int uint;

int main(void)
{
    union Number number;
    enum Weekday today = TUESDAY;
    uint age = 20;

    number.int_value = 100;

    printf("union 中的 int_value = %d\n", number.int_value);
    printf("today = %d\n", today);
    printf("typedef 定义的 uint age = %u\n", age);

    return 0;
}
