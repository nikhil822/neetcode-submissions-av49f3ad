class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        vector<int> startingSq;
        unordered_map<int, int> mp;
        for(auto i : nums) {
            mp[i]++;
        }
        for(auto i : nums) {
            if(mp[i - 1] == 0)startingSq.push_back(i);
        }
        int res = 0;
        for(auto i : startingSq) {
            int cnt = 0;
            for(int j = i; mp[j] != 0; j++) {
                cnt++;
                res = max(res, cnt);
            }
        }
        return res;
    }
};
