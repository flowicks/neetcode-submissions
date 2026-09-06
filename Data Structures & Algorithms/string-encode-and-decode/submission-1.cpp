class Solution {
private:
    std::string encodeSize(std::uint16_t size) {
        std::string res = "000";
        for (std::uint8_t i = res.size()-1; size != 0 && i < res.size(); --i) {
            res[i] = '0' + (size % 10);
            size /= 10;
        }
        return res;
    }
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        std::string res;
        res.reserve(200 * strs.size() + 3 * strs.size()); // worst case
        for (const auto& str : strs) {
            res += encodeSize(str.size());
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        std::vector<std::string> res;
        for (std::size_t i = 0; i < s.size(); ++i) {
            std::size_t strSize = s[i] - '0';
            strSize = strSize*10 + (s[++i] - '0');
            strSize = strSize*10 + (s[++i] - '0');
            i++;
            res.emplace_back(s.begin()+i, s.begin()+i+strSize);
            i += strSize-1;
        }
        return res;
    }
};
