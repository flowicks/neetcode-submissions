class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        std::unordered_set<char> seen;
        seen.reserve(s.size());

        std::size_t res = 0;

        for (std::size_t right = 0, left = 0; right < s.size(); ++right) {
            while (seen.contains(s[right])) seen.erase(s[left++]);
            res = std::max(res, right - left + 1);
            seen.insert(s[right]);
        }
        return res;
    }
};
