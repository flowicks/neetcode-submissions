class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> vec;
        vec.reserve(tokens.size());

        for (const auto& i : tokens) {
            if (i.size() > 1) {
                vec.push_back(std::stoi(i));
                continue;
            }
            std::size_t last = vec.size()-1;
            switch (i[0]) {
                case '+': vec[last-1] += vec[last]; vec.pop_back(); break;
                case '*': vec[last-1] *= vec[last]; vec.pop_back(); break;
                case '-': vec[last-1] -= vec[last]; vec.pop_back(); break;
                case '/': vec[last-1] /= vec[last]; vec.pop_back(); break;
                default: vec.push_back(i[0] - '0');
            }
        }
        return vec.back();
    }
};
