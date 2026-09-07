class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::int64_t product = 1;
        bool zero = false;
        for (const auto i : nums) {
            if (i == 0) {
                if (zero) return std::vector(nums.size(), 0);
                zero = true;
            }
            else product *= i;
        }
        std::vector<int> res;
        res.reserve(nums.size());
        for (const auto i : nums) {
            if (zero) {
                if (i == 0) res.push_back(product);
                else res.push_back(0);
            }
            else res.push_back(product / i);
        }
        return res;
    }
};
