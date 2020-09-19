
// https://leetcode-cn.com/problems/implement-strstr/

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