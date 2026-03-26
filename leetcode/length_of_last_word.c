#include <assert.h>
#include <stdio.h>

/*
 * 题目：最后一个单词的长度
 * 难度：简单
 * 练习点：字符串、字符遍历、空格处理、边界判断
 *
 * 题意（改写）：
 * 给你一个只包含英文大小写字母和空格的字符串 s，
 * 返回字符串中最后一个单词的长度。
 * 如果末尾有空格，需要先忽略这些空格。
 *
 * 示例：
 * 输入："Hello World"
 * 输出：5
 */

int lengthOfLastWord(char *s)
{
    (void)s;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

static void run_tests(void)
{
    char s1[] = "Hello World";
    char s2[] = "   fly me   to   the moon  ";
    char s3[] = "luffy is still joyboy";

    assert(lengthOfLastWord(s1) == 5);
    assert(lengthOfLastWord(s2) == 4);
    assert(lengthOfLastWord(s3) == 6);
}

#ifdef RUN_TESTS
int main(void)
{
    run_tests();
    printf("length_of_last_word.c: all tests passed\n");
    return 0;
}
#endif
