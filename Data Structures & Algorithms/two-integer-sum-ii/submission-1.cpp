class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int start = 0, end = numbers.size()-1; start < end;) {
            int sum = numbers[start] + numbers[end];
            if (sum < target) ++start;
            else if (sum > target) --end;
            else return {start+1, end+1};
        }
        return {0, 0};
    }
};
