// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
int lengthOfLongestSubstring(char* s) {
    // 数组模拟 hash,记录字符上一次出现的位置
    int lastPosition[256];
    for (int i = 0; i < 256; i ++) {
        lastPosition[i] = -1;
    }

    int left = 0;// 滑动窗口的左边
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right ++){
        char current = s[right];
        // 判断是不是在窗口内,上一次出现的位置
        if (lastPosition[current] >= left){
            left = lastPosition[current] + 1;
        }

        lastPosition[current] = right;

        int len = right - left + 1;
        maxLen = maxLen > len ? maxLen: len;
    }

    return maxLen;
}