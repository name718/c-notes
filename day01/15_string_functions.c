/*
 * 文件名：15_string_functions.c
 * 学习目标：
 * 1. 掌握常见字符串函数的基本用法
 * 2. 理解这些函数容易出错的地方
 *
 * 核心知识点：
 * - strlen：求字符串长度（不含 '\0'）
 * - strcpy：复制字符串
 * - strcmp：比较字符串
 * - strcat：拼接字符串
 *
 * 易错点：
 * - 目标数组空间不足会导致越界
 * - strcmp 比较的是字典序，不是简单判断长度
 *
 * 面试考点：
 * - strlen 返回的是不是数组总大小？答：不是，它返回字符串长度，不算 '\0'
 * - 为什么 strcpy 有风险？答：不检查目标缓冲区大小
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char source[] = "world";
    char target[20] = "hello ";

    printf("source 长度：%zu\n", strlen(source));

    strcat(target, source);
    printf("拼接后：%s\n", target);

    printf("strcmp(\"abc\", \"abd\") = %d\n", strcmp("abc", "abd"));

    strcpy(target, "reset");
    printf("复制后：%s\n", target);

    return 0;
}
