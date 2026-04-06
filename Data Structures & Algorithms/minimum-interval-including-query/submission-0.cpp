class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    int n = intervals.size();
    int m = queries.size();

    sort(intervals.begin(), intervals.end());

    // Store query with original index
    vector<pair<int,int>> q;
    for(int i = 0; i < m; i++) {
        q.push_back({queries[i], i});
    }

    sort(q.begin(), q.end());

    // Min heap: {interval_length, interval_end}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> ans(m, -1);
    int j = 0;

    for(int i = 0; i < m; i++) {
        int query = q[i].first;
        int idx = q[i].second;

        // Add valid intervals
        while(j < n && intervals[j][0] <= query) {
            int len = intervals[j][1] - intervals[j][0] + 1;
            pq.push({len, intervals[j][1]});
            j++;
        }

        // Remove invalid intervals
        while(!pq.empty() && pq.top().second < query) {
            pq.pop();
        }

        if(!pq.empty()) {
            ans[idx] = pq.top().first;
        }
    }

    return ans;
}
};
