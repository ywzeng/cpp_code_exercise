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
