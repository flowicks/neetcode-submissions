class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, std::uint32_t> freq;
        freq.reserve(nums.size());
        for (const auto i : nums) freq[i]++;
        std::vector<std::pair<int, std::uint32_t>> freqVec(freq.begin(), freq.end());
        std::sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        std::vector<int> res;
        res.reserve(k);
        for (std::size_t i = 0; i < k && i < freqVec.size(); i++) {
            res.push_back(freqVec[i].first);
        }
        return res;
    }
};
