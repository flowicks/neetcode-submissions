class Solution {
public:
    bool isValid(string s) {
        std::vector<char> vec;
        vec.reserve(s.size());
        for (const auto c : s) {
            if (c == '[' || c == '(' || c == '{') vec.push_back(c);
            else if (vec.empty()) return false;
            else {
                char closed = c == ')' ? '(' : c-2;
                if (vec.back() == closed) vec.pop_back();
                else return false;
            } 
        }
        return vec.empty();
    }
};
