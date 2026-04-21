// #include <assert.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    // 先计算字符串长度
    int sLen = 0;
    while (s[sLen] != '\0') sLen++;
    
    int pLen = 0;
    while (p[pLen] != '\0') pLen++;
    
    // 如果s比p短，不可能有异位词
    if (sLen < pLen) {
        *returnSize = 0;
        return NULL;
    }
    
    // 使用两个数组记录字符频率
    int pCount[26] = {0};  // p串的字符频率
    int windowCount[26] = {0};  // 当前窗口的字符频率
    
    // 统计p中每个字符的出现次数
    for (int i = 0; i < pLen; i++) {
        pCount[p[i] - 'a']++;
    }
    
    // 用于存储结果的数组（最多sLen个起始位置）
    int* result = (int*)malloc(sizeof(int) * sLen);
    int resultIndex = 0;
    
    // 滑动窗口
    int left = 0;
    for (int right = 0; right < sLen; right++) {
        // 将当前字符加入窗口
        windowCount[s[right] - 'a']++;
        
        // 当窗口大小超过pLen时，移动左边界
        if (right - left + 1 > pLen) {
            windowCount[s[left] - 'a']--;
            left++;
        }
        
        // 检查当前窗口是否是异位词
        if (right - left + 1 == pLen) {
            int isAnagram = 1;
            for (int i = 0; i < 26; i++) {
                if (pCount[i] != windowCount[i]) {
                    isAnagram = 0;
                    break;
                }
            }
            if (isAnagram) {
                result[resultIndex++] = left;
            }
        }
    }
    
    *returnSize = resultIndex;
    return result;
}

// int* findAnagrams(char* s, char* p, int* returnSize) {
//     int sLen = strlen(s);
//     int pLen = strlen(p);
    
//     if (sLen < pLen) {
//         *returnSize = 0;
//         return NULL;
//     }
    
//     int count[26] = {0};
    
//     // 使用p的字符作为正计数，s窗口作为负计数
//     for (int i = 0; i < pLen; i++) {
//         count[p[i] - 'a']++;
//         count[s[i] - 'a']--;
//     }
    
//     int* result = (int*)malloc(sizeof(int) * sLen);
//     int resultIndex = 0;
    
//     // 检查初始窗口
//     int zeroCount = 0;
//     for (int i = 0; i < 26; i++) {
//         if (count[i] == 0) zeroCount++;
//     }
//     if (zeroCount == 26) {
//         result[resultIndex++] = 0;
//     }
    
//     // 滑动窗口
//     for (int i = pLen; i < sLen; i++) {
//         // 移除左边的字符
//         int leftChar = s[i - pLen] - 'a';
//         if (count[leftChar] == 0) zeroCount--;
//         count[leftChar]++;
//         if (count[leftChar] == 0) zeroCount++;
        
//         // 添加右边的字符
//         int rightChar = s[i] - 'a';
//         if (count[rightChar] == 0) zeroCount--;
//         count[rightChar]--;
//         if (count[rightChar] == 0) zeroCount++;
        
//         // 如果所有计数器都为0，说明是异位词
//         if (zeroCount == 26) {
//             result[resultIndex++] = i - pLen + 1;
//         }
//     }
    
//     *returnSize = resultIndex;
//     return result;
// }