class Solution_stupid {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res_vec;
        for(auto i = 0; i < nums.size(); ++i) {
            for(auto j = i + 1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    res_vec.emplace_back(i);
                    res_vec.emplace_back(j);
                    return res_vec;
                }
            }
        }
        return res_vec;
    }
};
