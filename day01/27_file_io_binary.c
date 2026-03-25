/*
 * 文件名：27_file_io_binary.c
 * 学习目标：
 * 1. 掌握 fread、fwrite 的基本用途
 * 2. 理解文本文件和二进制文件的区别
 *
 * 核心知识点：
 * - 二进制读写直接面向字节
 * - 适合结构化数据或需要原样保存内存内容的场景
 *
 * 易错点：
 * - 二进制文件内容通常不便于直接人眼查看
 * - fread/fwrite 的参数顺序要记清
 *
 * 面试考点：
 * - 文本文件和二进制文件区别？答：一个面向字符表示，一个面向原始字节
 * - 为什么结构体常用二进制方式保存？答：实现简单，但要注意跨平台兼容性
 */

#include <stdio.h>

struct Item
{
    int id;
    double price;
};

int main(void)
{
    FILE *fp = fopen("item.bin", "wb");
    struct Item item = {1, 19.9};

    if (fp == NULL)
    {
        printf("二进制文件打开失败。\n");
        return 1;
    }

    fwrite(&item, sizeof(struct Item), 1, fp);
    fclose(fp);

    printf("已写入二进制文件 item.bin\n");

    return 0;
}
