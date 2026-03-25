/*
 * 文件名：26_file_io_basic.c
 * 学习目标：
 * 1. 掌握文本文件读写基本流程
 * 2. 认识 fopen、fprintf、fscanf、fclose
 *
 * 核心知识点：
 * - 打开文件：fopen
 * - 写文件：fprintf
 * - 读文件：fscanf
 * - 关闭文件：fclose
 *
 * 易错点：
 * - 文件打开后要判空
 * - 使用结束后要关闭文件
 *
 * 面试考点：
 * - fopen 不同模式什么意思？答：如 r、w、a、rb、wb
 * - 为什么 fclose 很重要？答：释放资源、刷新缓冲区
 *
 * 说明：
 * - 为了不依赖外部文件，本示例只演示写文件流程。
 */

#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("day01_demo.txt", "w");

    if (fp == NULL)
    {
        printf("文件打开失败。\n");
        return 1;
    }

    fprintf(fp, "name=Alice score=95\n");
    fclose(fp);

    printf("已写入文本文件 day01_demo.txt\n");

    return 0;
}
