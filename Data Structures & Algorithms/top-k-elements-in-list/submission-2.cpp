class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int sz = nums.size();
        unordered_map<int, int> freq;
        for(auto i : nums) {
            freq[i]++;
        }
        vector<vector<int>> temp(sz + 1);
        for(auto i : freq) {
            temp[i.second].push_back(i.first);
        }
        vector<int> ans;
        for(int i = sz; i >= 0; i--) {
            for(auto j : temp[i]) {
                if(k > 0) {
                    ans.push_back(j);
                    k--;
                }
            }
        }
        return ans;
    }
};
