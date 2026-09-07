class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const std::unordered_set<int> uniq(nums.begin(), nums.end());
        std::uint64_t res = 0;
        for (const auto i : nums) {
            if (uniq.contains(i-1)) continue;
            std::uint64_t currMax = 1;
            for (int j = i+1; uniq.contains(j); j++) currMax++;
            res = std::max(res, currMax);
        }
        return res;
    }
};
