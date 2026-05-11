// 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

// 值 0 代表空单元格；
// 值 1 代表新鲜橘子；
// 值 2 代表腐烂的橘子。
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
#include <stdbool.h>

#define EMPTY_CELL 0    // 空单元格
#define FRESH_ORANGE 1  // 新鲜橘子
#define ROTTEN_ORANGE 2 // 腐烂橘子

typedef struct
{
    int r, c; // 坐标
} Point;

int orangesRotting(int **grid, int gridSize, int *gridColSize)
{
    int rows = gridSize;
    int cols = gridColSize[0];
    int freshCount = 0;

    Point *queue = (Point *)malloc(sizeof(Point) * rows * cols);
    int head = 0; // 队头
    int tail = 0; // 队尾

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == FRESH_ORANGE)
            {
                freshCount++;
            }

            if (grid[i][j] == ROTTEN_ORANGE)
            {
                queue[tail++] = (Point){i, j}; // 入队是tail
            }
        }
    }

    // 没有新鲜橘子直接返回 0
    if (freshCount == 0)
    {
        free(queue);
        return 0;
    }

    int time = 0;

    while (head < tail)
    {
        // 当前层个数
        int size = tail - head;

        // 只遍历当前这一层
        for (int i = 0; i < size; i++)
        {
            Point curr = queue[head++]; // 出队

            // 下
            if (curr.r + 1 < rows && grid[curr.r + 1][curr.c] == FRESH_ORANGE)
            {
                grid[curr.r + 1][curr.c] = ROTTEN_ORANGE; // 标记腐烂
                freshCount--;
                queue[tail++] = (Point){curr.r + 1, curr.c};
            }
            // 上
            if (curr.r - 1 >= 0 && grid[curr.r - 1][curr.c] == FRESH_ORANGE)
            {
                grid[curr.r - 1][curr.c] = ROTTEN_ORANGE;
                freshCount--;
                queue[tail++] = (Point){curr.r - 1, curr.c};
            }
            // 右
            if (curr.c + 1 < cols && grid[curr.r][curr.c + 1] == FRESH_ORANGE)
            {
                grid[curr.r][curr.c + 1] = ROTTEN_ORANGE;
                freshCount--;
                queue[tail++] = (Point){curr.r, curr.c + 1};
            }

            // 左（你原来写错成 curr.r-1，帮你修正）
            if (curr.c - 1 >= 0 && grid[curr.r][curr.c - 1] == FRESH_ORANGE)
            {
                grid[curr.r][curr.c - 1] = ROTTEN_ORANGE;
                freshCount--;
                queue[tail++] = (Point){curr.r, curr.c - 1};
            }
        }
        // 每走完一层 才加1分钟
        (head < tail) && (time++);
    }

    free(queue);
    // 还有新鲜橘子剩 返回-1
    return freshCount != 0 ? -1 : time;
}