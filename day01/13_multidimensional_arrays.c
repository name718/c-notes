/*
 * 文件名：13_multidimensional_arrays.c
 * 学习目标：
 * 1. 掌握二维数组定义和访问方式
 * 2. 理解二维数组按行存储
 *
 * 核心知识点：
 * - 二维数组本质上是“数组的数组”
 * - 内存中通常按行连续存放
 *
 * 易错点：
 * - 遍历时行列边界不要写错
 * - 作为函数参数传递时，列数常常需要明确
 *
 * 面试考点：
 * - 二维数组在内存中如何存？答：按行连续存储
 * - arr[i][j] 的本质是什么？答：在指针意义上可理解为 *(*(arr + i) + j)
 */

#include <stdio.h>

int main(void)
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int row = 0;
    int col = 0;

    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 3; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}
