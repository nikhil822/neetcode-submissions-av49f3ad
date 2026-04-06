class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> outDeg(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(auto j : adj[i]) {
                outDeg[j]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(outDeg[i] == 0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : adj[node] ) {
                outDeg[i]--;
                if(outDeg[i] == 0)q.push(i);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};
