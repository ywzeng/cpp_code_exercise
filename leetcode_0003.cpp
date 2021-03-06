class Solution_dp {
public:
    int lengthOfLongestSubstring(string s) {
        int char_set[128];      // Store the last-seen-index of the char in s.
        fill(char_set, char_set+128, -1);
        int str_start_index = -1;
        int max_len = 0;
        for(int i = 0; i < s.length(); ++i) {
            int char_index = s[i];
            // The character is already in the sub-string.
            if(char_set[char_index] > str_start_index) {
                // Set str_start_index to the last-seen-index of current character.
                str_start_index = char_set[char_index];
            }
            max_len = max(max_len, i - str_start_index);
            char_set[char_index] = i;
        }
        return max_len;
    }
};


class Solution_double_pointerr {
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
