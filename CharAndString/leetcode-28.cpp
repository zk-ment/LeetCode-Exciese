
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:
// 输入: haystack = "hello", needle = "ll"
// 输出: 2

// 示例 2:
// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size(), 0);
        for (int i = 1, j = 0; i < needle.size();) {
            if (needle[i] == needle[j]) {
                next[i] = j + 1;
                i++;
                j++;
            } else {
                if (j == 0) {
                    next[i] = 0;
                    i++;
                } else {
                    j = next[j - 1];
                }
            }
        }
        int res = -1;
        for (int i = 0, j = 0; i < haystack.size();) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == needle.size()) {
                    res = i - j;
                    break;
                }
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = next[j - 1];
                }
            }
        }
        return res;
    }
};