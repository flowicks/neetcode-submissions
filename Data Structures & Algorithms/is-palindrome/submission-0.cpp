class Solution {
public:
    bool isPalindrome(string s) {
        for (std::size_t start = 0, end = s.size()-1; start < end && end < s.size();) {
            while (start < s.size() && !std::isalnum(s[start])) ++start;
            if (start == s.size()) break;
            while (end < s.size() && !std::isalnum(s[end])) --end;
            if (end <= start) break;
            if (std::tolower(s[start++]) != std::tolower(s[end--])) return false;
        }
        return true;
    }
};
