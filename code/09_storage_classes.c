/*
 * 文件名：09_storage_classes.c
 * 学习目标：
 * 1. 认识 auto、static、extern、register
 * 2. 理解 static 在不同场景下的作用
 *
 * 核心知识点：
 * - auto：局部变量的默认存储类别，通常很少显式写
 * - static：可修饰局部变量、全局变量、函数
 * - extern：声明“这个变量/函数在别处定义”
 * - register：建议编译器把变量放入寄存器（现代编译器未必理会）
 *
 * 易错点：
 * - extern 是声明，不是定义
 * - static 局部变量只初始化一次，不会每次调用都重置
 *
 * 面试考点：
 * - static 的常见作用？答：延长局部变量生命周期、限制全局符号作用域
 * - extern 的本质？答：告诉编译器去别处找定义
 */

#include <stdio.h>

void visit_counter(void)
{
    static int count = 0;
    count++;
    printf("当前函数已调用 %d 次\n", count);
}

int main(void)
{
    auto int number = 10;
    register int i = 0;

    printf("auto 变量 number = %d\n", number);

    for (i = 0; i < 3; i++)
    {
        visit_counter();
    }

    return 0;
}
