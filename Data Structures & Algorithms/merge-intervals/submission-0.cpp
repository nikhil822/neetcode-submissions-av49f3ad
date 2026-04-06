class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n;) {
            int j = i + 1, e = intervals[i][1];
            while(j < n && e >= intervals[j][0]) {
                e = max(e, intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], e});
            i = j;
        }
        return ans;
    }
};
