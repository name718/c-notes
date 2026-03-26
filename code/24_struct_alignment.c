/*
 * 文件名：24_struct_alignment.c
 * 学习目标：
 * 1. 理解结构体对齐现象
 * 2. 学会观察 sizeof(struct) 为什么可能大于成员之和
 *
 * 核心知识点：
 * - 编译器常为提高访问效率进行内存对齐
 * - 结构体大小往往不是简单相加
 *
 * 易错点：
 * - 不同平台、编译器、对齐规则可能不同
 * - 面试时不要死背结果，要会解释“为什么可能不同”
 *
 * 面试考点：
 * - 什么是结构体对齐？答：编译器按对齐规则插入填充字节
 * - 为什么要对齐？答：通常为了提高访问效率并满足硬件要求
 */

#include <stdio.h>

struct Demo
{
    char a;
    int b;
    char c;
};

int main(void)
{
    printf("sizeof(struct Demo) = %zu\n", sizeof(struct Demo));
    printf("成员大小之和 = %zu\n", sizeof(char) + sizeof(int) + sizeof(char));
    printf("如果结果更大，通常就是发生了对齐填充。\n");

    return 0;
}
