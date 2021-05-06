class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res = {first};
        for (auto &item: encoded) {
            res.emplace_back(item ^ res.back());
        }
        return res;
    }
};
