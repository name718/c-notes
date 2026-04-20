// https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked

// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49 
// 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

int maxArea(int* height, int heightSize) {
    if (heightSize < 2) return 0;
    int maxA = 0;

    int left = 0;
    int right = heightSize - 1;

    // 不用 for，用 while 最干净（你用for会自己跳，坑）
    while (left < right) {
        // 取矮的
        int minHeight = height[left] < height[right] ? height[left] : height[right];
        // 宽度：right - left
        int area = minHeight * (right - left);

        // 更新最大面积
        if (area > maxA) {
            maxA = area;
        }

        // 谁矮谁移动
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxA;  // 这里返回 maxA！
}
