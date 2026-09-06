class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (std::size_t i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            auto it = std::find(nums.begin()+i+1, nums.end(), other);
            if (it == nums.end() || *it != other) continue;
            return {static_cast<int>(i), static_cast<int>(it - nums.begin())};
        }
        return {0, 0};
    }
};
