/*
 * 文件名：29_const_vs_define.c
 * 学习目标：
 * 1. 理解 const 与 #define 都能表示“常量”场景
 * 2. 掌握二者在本质和面试表达上的区别
 *
 * 核心知识点：
 * - const：定义只读对象，通常有类型
 * - #define：预处理宏，做文本替换
 *
 * 易错点：
 * - const 不是简单的“预处理替换”
 * - #define 没有类型检查，复杂宏容易埋坑
 *
 * 面试考点（高频）：
 * - const 和 #define 区别？
 *   1. 处理阶段不同：const 在编译阶段参与语义分析，#define 在预处理阶段替换
 *   2. 类型不同：const 有类型，#define 宏常量本身没有类型
 *   3. 调试体验不同：const 通常更容易被调试器识别
 *   4. 安全性不同：#define 本质是文本替换，更容易产生副作用
 */

#include <stdio.h>

#define MAX_STUDENTS 60

int main(void)
{
    const int max_score = 100;

    printf("const 常量 max_score = %d\n", max_score);
    printf("#define 宏常量 MAX_STUDENTS = %d\n", MAX_STUDENTS);
    printf("面试回答关键词：处理阶段、是否有类型、是否只是文本替换。\n");

    return 0;
}
