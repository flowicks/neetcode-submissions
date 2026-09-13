class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int currProfit = 0;
        
        for (const auto i : prices) {
            if (i <= currMin) currMin = i;
            else currProfit = std::max(i - currMin, currProfit);
        }
        return currProfit;
    }
};
