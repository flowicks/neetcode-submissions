class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size());
        for (const auto i : nums) {
            if (seen.contains(i)) return true;
            seen.insert(i);
        }
        return false;
    }
};