// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

#define OCEAN '0'
#define LAND '1'

void dfs(char **grid, int row, int col, int i, int j);

int numIslands(char **grid, int gridSize, int *gridColSize)
{
    // dfs

    int row = gridSize;
    int col = gridColSize[0];
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == LAND)
            {
                // dfs
                count++;
                dfs(grid, row, col, i, j);
            }
        }
    }

    return count;
}

void dfs(char **grid, int row, int col, int i, int j)
{
    if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == OCEAN)
    {
        return;
    }

    grid[i][j] = OCEAN;

    dfs(grid, row, col, i + 1, j);
    dfs(grid, row, col, i - 1, j);
    dfs(grid, row, col, i, j + 1);
    dfs(grid, row, col, i, j - 1);
}