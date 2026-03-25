/*
 * 文件名：00_hello_world.c
 * 学习目标：
 * 1. 认识一个最小 C 程序的基本结构
 * 2. 理解 #include、main 函数、return 0 的作用
 *
 * 核心知识点：
 * - 预处理指令：#include <stdio.h>
 * - 程序入口：int main(void)
 * - 输出函数：printf
 *
 * 易错点：
 * - 忘记包含 stdio.h，会导致 printf 没有声明
 * - main 推荐返回 int，而不是 void
 *
 * 面试考点：
 * - C 程序从哪里开始执行？答：从 main 函数开始
 * - main 为什么返回 int？答：向操作系统返回退出状态码
 * - return 0 表示什么？答：通常表示程序正常结束
 */

#include <stdio.h>

int main(void)
{
    printf("Hello, C language!\n");
    printf("这是你的第一个 C 程序。\n");

    return 0;
}
