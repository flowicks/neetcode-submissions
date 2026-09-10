class Solution {
public:
    int maxArea(vector<int>& heights) {
        std::size_t res = 0;

        for (std::int64_t left = 0, right = heights.size()-1; left < right; ) {
            std::size_t area = (right - left) * std::min(heights[left], heights[right]);
            res = std::max(res, area);
            if (heights[left] <= heights[right]) left++;
            else right--;
        }
        return res;
    }
};
