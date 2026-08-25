class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = 1, currMin = 1, res = nums[0];
        for(auto i : nums) {
            int oldMax = currMax, oldMin = currMin;
            currMax = max({i, i * oldMax, i * oldMin});
            currMin = min({i, i * oldMax, i * oldMin});
            res = max(res, currMax);
        }
        return res;
    }
};
