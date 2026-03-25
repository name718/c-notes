/*
 * 文件名：28_preprocessor_basic.c
 * 学习目标：
 * 1. 认识 C 预处理器做什么
 * 2. 掌握 #include、#define、条件编译基础
 *
 * 核心知识点：
 * - #include：把头文件内容展开进来
 * - #define：进行宏替换
 * - #if/#ifdef：条件编译
 *
 * 易错点：
 * - 预处理是文本层面的替换，不做类型检查
 * - 宏常量没有类型概念
 *
 * 面试考点：
 * - 预处理发生在编译哪一步？答：在正式编译前
 * - #include 本质是什么？答：把被包含文件内容展开到当前位置
 */

#include <stdio.h>

#define PI 3.14159
#define DEBUG 1

int main(void)
{
    printf("PI = %.5f\n", PI);

#if DEBUG
    printf("当前处于调试模式。\n");
#endif

    return 0;
}
