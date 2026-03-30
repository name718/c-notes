#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * LeetCode 题号：20
 * 题目：Valid Parentheses
 * 地址：https://leetcode.com/problems/valid-parentheses/
 */

/*
 * 题目：有效的括号
 * 难度：简单
 * 练习点：栈、字符串遍历、括号匹配
 *
 * 题意（改写）：
 * 给定只包含 '(', ')', '{', '}', '[' 和 ']' 的字符串 s，
 * 判断字符串是否有效：左括号必须用相同类型右括号闭合，且顺序正确。
 *
 * 算法描述：
 * 1. 遇到左括号入栈。
 * 2. 遇到右括号时，检查栈顶是否为匹配的左括号。
 * 3. 遍历结束后栈为空则有效。
 */

bool isValid(char *s)
{
    (void)s;

    /* TODO: 在这里完成具体实现 */
    return false;
}
