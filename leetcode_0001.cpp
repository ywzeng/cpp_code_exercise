class Solution_Stupid {
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


class Solution_Map {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> item_vec;
        map<int, int> temp_map;
        for(int i = 0; i < nums.size(); ++i) {
            temp_map.insert(pair<int, int>(nums[i], i));
        }
        for(int i = 0; i < nums.size(); ++i) {
            auto temp_iter = temp_map.find(target - nums[i]);
            if(temp_iter != temp_map.end() && temp_iter->second != i) {
                item_vec.emplace_back(i);
                item_vec.emplace_back(temp_iter->second);
                break;
            }
        }
        return item_vec;
    }
};
