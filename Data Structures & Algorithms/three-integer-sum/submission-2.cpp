class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        res.reserve(nums.size()/3);
        
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) continue;
            if (i > 0 && nums[i-1] == nums[i]) continue;

            std::int64_t target = -nums[i];
            for (std::int64_t left = i+1, right = nums.size()-1; left < right;) {
                std::int64_t sum = nums[left] + nums[right];
                if (sum < target) left++;
                else if (sum > target) right--;
                else {
                    res.push_back({nums[i], nums[left++], nums[right--]});
                    while (left < right && nums[left-1] == nums[left]) left++; 
                }
            }
        }
        return res;
    }
};
