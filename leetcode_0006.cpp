class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() <= numRows || numRows == 1) return s;
        vector<string> res_vec;
        for (int i = 0; i < numRows; ++i) {
            res_vec.push_back(string(""));
        }
        int str_index = 0;
        bool direction = true;
        for (int i = 0; i < s.length(); ++i) {
            res_vec[str_index].push_back(s[i]);
            if (direction) {
                if (str_index < numRows - 1) {
                    ++str_index;
                } else {
                    --str_index;
                    direction = false;
                }
            } else {
                if (str_index > 0) {
                    --str_index;
                } else {
                    ++str_index;
                    direction = true;
                }
            }
        }
        string res_str;
        for (int i = 0; i < res_vec.size(); ++i) {
            res_str += res_vec[i];
        }
        return res_str;
    }
};
