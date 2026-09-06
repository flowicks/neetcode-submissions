class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        std::array<int, 26> freq;
        for (const auto c : s) freq[c - 'a']++;
        for (const auto c : t) {
            if (--freq[c - 'a'] < 0) return false;
        }
        for (const auto i : freq) {
            if (i != 0) return false;
        }
        return true;
    }
};
