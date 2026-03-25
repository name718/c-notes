/*
 * 文件名：11_header_guard.c
 * 学习目标：
 * 1. 理解头文件重复包含问题
 * 2. 掌握 include guard 的基本写法
 *
 * 核心知识点：
 * - 同一个头文件可能被间接包含多次
 * - 使用 #ifndef / #define / #endif 防止重复展开
 *
 * 易错点：
 * - 头文件保护宏名称不要和别的文件冲突
 * - 不加保护可能导致重复定义、重复声明问题
 *
 * 面试考点：
 * - 为什么要写头文件保护？答：避免头文件内容被多次展开
 * - #pragma once 和 include guard 区别？答：前者更简洁，但本质是编译器扩展
 */

#include <stdio.h>

int main(void)
{
    printf("常见头文件保护写法：\n");
    printf("#ifndef MY_HEADER_H\n");
    printf("#define MY_HEADER_H\n");
    printf("/* 声明内容 */\n");
    printf("#endif\n");

    return 0;
}
