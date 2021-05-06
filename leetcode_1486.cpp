class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums = {start};
        int res = start;
        for (int i = 1; i < n; ++i) {
            int temp = start + 2 * i;
            nums.emplace_back(temp);
            res ^= temp;
        }
        return res;
    }
};
