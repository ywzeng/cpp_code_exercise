class Solution_CenterExpand {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        int max_len = 1;
        string res_str = s.substr(0, 1);
        for (int i = 0; i < s.length(); ++i) {
            string even_str = center_expand(s, i, i + 1);
            string odd_str = center_expand(s, i, i);
            string long_str = even_str.length() > odd_str.length() ? even_str : odd_str;
            if (long_str.length() > max_len) {
                max_len = long_str.length();
                res_str = long_str;
            }
        }
        return res_str;
    }

private:
    string center_expand(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // When jump out of the while loop, `left` is not equal to `right`. The valid range is actually [left + 1, right - 1].
        return s.substr(left + 1, right - left - 1);
    }
};

class Solution_DP {
public:
    string longestPalindrome(string s) {
        // DP. Here, dp[i, j] is true indicates that both s[i] == s[j] and dp[i+1, j-1] is true.
        if (s.length() < 2) {
            return s;
        }
        vector<vector<bool> > dp(s.length(), vector<bool>(s.length()));
    
        int max_len = 1;
        int begin_index = 0;
        // Init the diagonal.
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
        }
        // Skip the diagonal.
        for (int j = 1; j < s.length(); ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    begin_index = i;
                }
            }
        }

        return s.substr(begin_index, max_len);
    }
};
