/*
 * 文件名：14_strings.c
 * 学习目标：
 * 1. 理解字符串在 C 中的表示方式
 * 2. 掌握 '\0' 结束符的意义
 *
 * 核心知识点：
 * - C 没有内建 string 类型，字符串通常用 char 数组表示
 * - 字符串结尾有一个隐藏的 '\0'
 *
 * 易错点：
 * - "abc" 实际占 4 个字符空间：'a' 'b' 'c' '\0'
 * - 字符和字符串要区分：'a' 与 "a" 不同
 *
 * 面试考点：
 * - 为什么 C 字符串要以 '\0' 结束？答：库函数靠它判断字符串结束位置
 * - char arr[] = "abc" 和 char *p = "abc" 有什么区别？答：一个是数组，一个是指针
 */

#include <stdio.h>

int main(void)
{
    char name[] = "Alice";

    printf("字符串内容：%s\n", name);
    printf("第一个字符：%c\n", name[0]);
    printf("字符串数组总大小：%zu\n", sizeof(name));

    return 0;
}
