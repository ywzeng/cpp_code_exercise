class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()) {
            return 0;
        }
        unordered_set<char> char_set;
        int max_len = 0;
        int left = 0;
        for(int right = left; right < s.length(); ++right) {
            // Check whether the current character is in the char_set.
            // If not, update the max_len and insert such character into the set.
            // Otherwise, increase the left pointer to narrow the slice window until there is no duplicated characters. Then Increase the right pointer to further broden the slice window.
            while(char_set.find(s[right]) != char_set.end()) {
                char_set.erase(s[left]);
                ++left;
            }
            max_len = max(max_len, right - left + 1);
            char_set.insert(s[right]);
        }
        return max_len;
    }
};
