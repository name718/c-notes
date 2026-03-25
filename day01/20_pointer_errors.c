/*
 * 文件名：20_pointer_errors.c
 * 学习目标：
 * 1. 认识常见指针错误类型
 * 2. 学会用安全写法规避问题
 *
 * 核心知识点：
 * - 空指针：值为 NULL 的指针
 * - 野指针：未初始化或指向非法区域的指针
 * - 悬空指针：指向已失效内存的指针
 *
 * 易错点：
 * - 未初始化的指针绝不能直接解引用
 * - free 之后最好把指针置为 NULL
 *
 * 面试考点：
 * - 野指针和悬空指针区别？答：一个可能从未指向合法对象，一个曾经合法但后来失效
 * - 为什么 free 后置 NULL 是好习惯？答：避免误用已释放地址
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *safe_ptr = NULL;
    int *heap_num = (int *)malloc(sizeof(int));

    if (heap_num == NULL)
    {
        printf("内存申请失败。\n");
        return 1;
    }

    *heap_num = 123;
    safe_ptr = heap_num;

    if (safe_ptr != NULL)
    {
        printf("safe_ptr 指向的值：%d\n", *safe_ptr);
    }

    free(heap_num);
    heap_num = NULL;
    safe_ptr = NULL;

    printf("释放后把指针置为 NULL，更安全。\n");

    return 0;
}
