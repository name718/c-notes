// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // 1. 定义入度数组和出度数组
    // inDegree 记录每个节点的入度（有几个先修课）
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    // outDegree 记录每个节点的出度（有几个后续课），用于精确分配邻接表的内存
    int* outDegree = (int*)calloc(numCourses, sizeof(int));

    // 第一次遍历：统计每个节点的出度
    for (int i = 0; i < prerequisitesSize; i++) {
        int pre = prerequisites[i][1]; // 先修课
        outDegree[pre]++;
    }

    // 2. 构建邻接表 (Adjacency List)
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    int* adjIndex = (int*)calloc(numCourses, sizeof(int)); // 辅助数组，记录当前邻接表填入数据的位置

    for (int i = 0; i < numCourses; i++) {
        if (outDegree[i] > 0) {
            adj[i] = (int*)malloc(outDegree[i] * sizeof(int));
        } else {
            adj[i] = NULL;
        }
    }

    // 第二次遍历：正式填充入度数组和邻接表
    for (int i = 0; i < prerequisitesSize; i++) {
        int crs = prerequisites[i][0]; // 想要学习的课
        int pre = prerequisites[i][1]; // 先修课
        
        inDegree[crs]++; // 想学的课入度 +1
        adj[pre][adjIndex[pre]++] = crs; // 把想要学的课放入先修课的“后续课程”名单中
    }

    // 3. BFS 寻找突破口（初始化队列）
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    // 将所有入度为 0 的课（没有任何门槛）入队
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[tail++] = i;
        }
    }

    // 4. BFS 剥洋葱
    int count = 0; // 记录成功学完的课程数

    while (head < tail) {
        int curr = queue[head++]; // 出队，表示这门课已经学完
        count++;

        // 遍历这门课的所有后续课程
        for (int i = 0; i < outDegree[curr]; i++) {
            int nextCourse = adj[curr][i];
            inDegree[nextCourse]--; // 因为当前课学完了，后续课程的限制（入度）减 1

            // 如果后续课程的限制减到了 0，说明可以学了，入队
            if (inDegree[nextCourse] == 0) {
                queue[tail++] = nextCourse;
            }
        }
    }

    // 5. 释放所有动态分配的内存（防止内存泄漏，C 语言好习惯）
    for (int i = 0; i < numCourses; i++) {
        if (adj[i] != NULL) {
            free(adj[i]);
        }
    }
    free(adj);
    free(inDegree);
    free(outDegree);
    free(adjIndex);
    free(queue);

    // 6. 得出结论：学完的课数是否等于总课程数
    return count == numCourses;
}