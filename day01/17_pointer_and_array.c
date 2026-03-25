/*
 * 文件名：17_pointer_and_array.c
 * 学习目标：
 * 1. 理解数组和指针的联系
 * 2. 认识“数组名退化为首元素地址”
 *
 * 核心知识点：
 * - 在多数表达式中，数组名会退化为首元素地址
 * - 指针可以通过偏移访问数组元素
 *
 * 易错点：
 * - 数组和指针相关，但它们不是完全相同的东西
 * - sizeof(array) 和 sizeof(pointer) 结果不同
 *
 * 面试考点：
 * - arr 和 &arr[0] 是否一样？答：数值上常相同，但类型语义不同
 * - 数组名是不是指针？答：不是，只是在很多场景下会退化为指针
 */

#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40};
    int *ptr = numbers;

    printf("numbers[0] = %d\n", numbers[0]);
    printf("*(ptr + 1) = %d\n", *(ptr + 1));
    printf("ptr[2] = %d\n", ptr[2]);

    printf("sizeof(numbers) = %zu\n", sizeof(numbers));
    printf("sizeof(ptr) = %zu\n", sizeof(ptr));

    return 0;
}
