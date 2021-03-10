class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for(int i = 0; i < S.length(); ++i) {
            if(res.empty() || S[i] != res.back()) {
                res += S[i];
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};
