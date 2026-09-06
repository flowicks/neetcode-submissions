class Solution {
using FreqArray = std::array<std::uint8_t, 26>;

private:
    struct HashFreq {
        std::uint64_t operator() (const FreqArray& array) const noexcept {
            uint64_t h = 0x9e3779b97f4a7c15ULL;
            constexpr const uint64_t prime = 0xc4ceb9fe1a85ec53ULL;

            for (std::uint8_t i = 0; i < array.size(); i++) {
                h ^= static_cast<std::uint64_t>(array[i]);
                h *= prime;
                h ^= (h >> 27);
            }

            h ^= h >> 33;
            h *= 0xff51afd7ed558ccdULL;
            h ^= h >> 33;
            return h;
        }
    };
    FreqArray getFreq(const std::string& str) const {
        FreqArray freq{};
        for (const auto c : str) freq[c - 'a']++;
        return freq;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<FreqArray, std::vector<std::string>, HashFreq> map;
        map.reserve(strs.size());
        for (const auto& str : strs) map[getFreq(str)].push_back(str);
        std::vector<std::vector<std::string>> res;
        res.reserve(map.size());
        for (auto& [_, vec] : map) {
            res.emplace_back(std::move(vec));
        }
        return res;
    }
};
