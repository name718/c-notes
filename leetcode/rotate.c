// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右轮转 1 步: [7,1,2,3,4,5,6]
// 向右轮转 2 步: [6,7,1,2,3,4,5]
// 向右轮转 3 步: [5,6,7,1,2,3,4]

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int left, int right, int *nums) {
    while (left < right)
    {
        swap(&nums[left], &nums[right]);
        left ++;
        right --;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (k == 0) return;
    // 首先将整个数组反转
    reverse(0, numsSize - 1, nums);
    // 然后将 前 k 个反转一次
    reverse(0, k - 1, nums);
    // 再将剩余的反转一次
    reverse(k, numsSize - 1, nums);
}