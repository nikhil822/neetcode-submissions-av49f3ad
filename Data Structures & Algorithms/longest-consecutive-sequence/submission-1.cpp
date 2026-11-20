class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& i : nums) {
            s.insert(i);
        }
        int cnt = 0;
        for(auto& i : s) {
            int prev = i - 1, temp = 1;
            if(s.count(prev) == 0) {
                int var = i + 1;
                while(s.count(var) > 0) {
                    temp++;
                    var++;
                }
            }
            cnt = max(cnt, temp);
        }
        return cnt;
    }
};