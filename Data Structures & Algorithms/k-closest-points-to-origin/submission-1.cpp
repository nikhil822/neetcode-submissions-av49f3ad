class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(auto i : points) {
            int dist = pow(abs(i[0]), 2) + pow(abs(i[1]), 2);
            double srt = sqrt(dist);
            if(pq.size() == k && pq.top().first > srt) {
                pq.pop();
            }
            if(pq.size() < k)
            pq.push({srt, {i[0], i[1]}});
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }

};
