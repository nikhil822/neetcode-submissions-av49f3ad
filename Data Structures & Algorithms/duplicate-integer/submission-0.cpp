class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto i : nums) {
            m[i]++;
            if(m[i] > 1)return true;
        }
        return false;
    }
};