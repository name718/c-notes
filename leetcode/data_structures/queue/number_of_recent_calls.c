#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LeetCode 题号：933
 * 题目：Number of Recent Calls
 * 地址：https://leetcode.com/problems/number-of-recent-calls/
 */

/*
 * 题目：最近的请求次数
 * 难度：简单
 * 练习点：队列、滑动窗口、时间区间维护
 *
 * 题意（改写）：
 * 每次 ping(t) 返回时间区间 [t-3000, t] 内请求数量。
 *
 * 算法描述：
 * 1. 用队列保存所有请求时间。
 * 2. 新请求入队后，持续弹出小于 t-3000 的时间。
 * 3. 队列长度即当前答案。
 */

typedef struct {
    int placeholder;
} RecentCounter;

RecentCounter *recentCounterCreate(void)
{
    /* TODO: 在这里完成具体实现 */
    return NULL;
}

int recentCounterPing(RecentCounter *obj, int t)
{
    (void)obj;
    (void)t;

    /* TODO: 在这里完成具体实现 */
    return 0;
}

void recentCounterFree(RecentCounter *obj)
{
    (void)obj;

    /* TODO: 在这里完成具体实现 */
}
