
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

// 示例 1:
// 输入: haystack = "hello", needle = "ll"
// 输出: 2

// 示例 2:
// 输入: haystack = "aaaaa", needle = "bba"
// 输出: -1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/implement-strstr

// Sunday算法

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> num(130, needle.size() + 1);
        for (int i = 0; i < needle.size(); i++){
            num[needle[i]] = needle.size() - i;
        }
        int res = -1;
        for (int i = 0, j = 0; i + needle.size() <= haystack.size(); j = 0) {
            while(j < needle.size() && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                res = i;
                break;
            }
            i += num[haystack[i + needle.size()]];
        }
        return res;
    }
};