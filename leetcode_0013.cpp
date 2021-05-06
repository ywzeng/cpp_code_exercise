class Solution {
public:
    int romanToInt(string s) {
        map<char, int> char_map;
        char_map.insert(make_pair('I', 1));
        char_map.insert(make_pair('V', 5));
        char_map.insert(make_pair('X', 10));
        char_map.insert(make_pair('L', 50));
        char_map.insert(make_pair('C', 100));
        char_map.insert(make_pair('D', 500));
        char_map.insert(make_pair('M', 1000));

        int res = 0;
        for (int i = 0; i < s.length();) {
            if (i < s.length() - 1 && char_map[s[i]] < char_map[s[i + 1]]) {
                res += char_map[s[i + 1]] - char_map[s[i]];
                i += 2;
                
            } else {
                res += char_map[s[i++]];
            }
        }
        return res;
    }
};
