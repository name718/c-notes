/*
 * 文件名：21_memory_layout.c
 * 学习目标：
 * 1. 建立 C 程序内存分区的基本认识
 * 2. 理解不同变量常见的存储区域
 *
 * 核心知识点：
 * - 代码区：存放程序指令
 * - 静态存储区：全局变量、static 变量
 * - 栈区：局部变量、函数调用信息
 * - 堆区：动态申请的内存
 *
 * 易错点：
 * - “常见存储位置”不等于标准强制实现细节
 * - 不要返回局部变量地址，离开函数后地址失效
 *
 * 面试考点：
 * - 栈和堆区别？答：管理方式、生命周期、使用场景不同
 * - 全局变量和 static 局部变量常放哪里？答：静态存储区
 */

#include <stdio.h>
#include <stdlib.h>

int global_var = 100;
static int static_global_var = 200;

void show_memory_layout(void)
{
    int local_var = 300;
    static int static_local_var = 400;
    int *heap_var = (int *)malloc(sizeof(int));

    if (heap_var == NULL)
    {
        printf("内存申请失败。\n");
        return;
    }

    *heap_var = 500;

    printf("全局变量地址：%p\n", (void *)&global_var);
    printf("静态全局变量地址：%p\n", (void *)&static_global_var);
    printf("局部变量地址：%p\n", (void *)&local_var);
    printf("静态局部变量地址：%p\n", (void *)&static_local_var);
    printf("堆内存地址：%p\n", (void *)heap_var);

    free(heap_var);
}

int main(void)
{
    show_memory_layout();
    return 0;
}
