#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * 题目：回文数
 * 难度：简单
 * 练习点：整数、取模、除法、循环、条件判断
 *
 * 题意（改写）：
 * 给你一个整数 x，如果它从左往右读和从右往左读都一样，
 * 就返回 true，否则返回 false。
 *
 * 示例：
 * 输入：121
 * 输出：true
 *
 * 输入：-121
 * 输出：false
 */

bool isPalindrome(int x)
{
    (void)x;

    /* TODO: 在这里完成具体实现 */
    return false;
}

static void run_tests(void)
{
    assert(isPalindrome(121) == true);
    assert(isPalindrome(-121) == false);
    assert(isPalindrome(10) == false);
    assert(isPalindrome(0) == true);
}

#ifdef RUN_TESTS
int main(void)
{
    run_tests();
    printf("palindrome_number.c: all tests passed\n");
    return 0;
}
#endif
