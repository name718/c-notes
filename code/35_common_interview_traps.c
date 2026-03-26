/*
 * 文件名：35_common_interview_traps.c
 * 学习目标：
 * 1. 汇总常见 C 面试陷阱题
 * 2. 训练“会写 + 会解释 + 知道风险”的能力
 *
 * 核心知识点：
 * - 未初始化变量值不确定
 * - 数组和指针不能简单画等号
 * - 字符和字符串不同
 * - 运算符优先级可能误导阅读
 *
 * 易错点：
 * - 不要依赖未定义行为
 * - 不要写过度复杂的表达式
 *
 * 面试考点：
 * - sizeof(arr) 和 sizeof(ptr) 为什么不同？
 * - 'a' 和 "a" 的区别？
 * - 为什么建议少写 i = i++ 这类代码？答：可读性差，还可能涉及未定义或未明确行为风险
 */

#include <stdio.h>

int main(void)
{
    char ch = 'a';
    char str[] = "a";
    int numbers[3] = {1, 2, 3};
    int *ptr = numbers;

    printf("'a' 是单个字符：%c\n", ch);
    printf("\"a\" 是字符串：%s\n", str);
    printf("sizeof(numbers) = %zu\n", sizeof(numbers));
    printf("sizeof(ptr) = %zu\n", sizeof(ptr));
    printf("结论：面试里既要会写代码，也要知道背后的原因。\n");

    return 0;
}
