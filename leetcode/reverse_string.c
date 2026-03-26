#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
 * 题目：反转字符串
 * 难度：简单
 * 练习点：字符数组、双指针、交换、字符串处理
 *
 * 题意（改写）：
 * 给你一个字符数组 s，请原地将它反转。
 * 只能修改原数组，不能额外申请一个同样大小的新数组来存结果。
 *
 * 示例：
 * 输入：['h','e','l','l','o']
 * 输出：['o','l','l','e','h']
 */

void reverseString(char *s, int sSize)
{
    (void)s;
    (void)sSize;

    /* TODO: 在这里完成具体实现 */
}

static void run_tests(void)
{
    {
        char s[] = "hello";
        reverseString(s, 5);
        assert(strcmp(s, "olleh") == 0);
    }

    {
        char s[] = "Hannah";
        reverseString(s, 6);
        assert(strcmp(s, "hannaH") == 0);
    }

    {
        char s[] = "a";
        reverseString(s, 1);
        assert(strcmp(s, "a") == 0);
    }
}

#ifdef RUN_TESTS
int main(void)
{
    run_tests();
    printf("reverse_string.c: all tests passed\n");
    return 0;
}
#endif
