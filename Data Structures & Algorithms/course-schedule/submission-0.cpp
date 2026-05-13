class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            inDeg[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDeg[i] == 0)q.push(i);
        }
        if(q.size() == 0)return false;
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto i : adj[top]) {
                inDeg[i]--;
                if(inDeg[i] == 0)q.push(i);
            }
        }
        for(auto i : inDeg){
            if(i != 0)return false;
        }
        return true;
    }
};
