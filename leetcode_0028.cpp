class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int h_len = haystack.length(), n_len = needle.length();
        int left = 0;
        while (left < h_len - n_len + 1) {
            if (haystack[left] == needle[0]) {
                bool matched = true;
                for (int i = 1; i < n_len; ++i) {
                    if (haystack[left + i] != needle[i]) {
                        matched = false;
                        break;
                    }
                }
                if (matched) {
                    return left;
                }
            }
            left++;
        }
        return -1;
    }
};
