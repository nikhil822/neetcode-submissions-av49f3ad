class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> vis(n, INT_MAX);
        vis[src] = 0;
        for(int i = 0; i <= k; i++) {
            vector<int> temp = vis;
            for(auto j : flights) {
                if(vis[j[0]] != INT_MAX && temp[j[1]] > vis[j[0]] + j[2]) {
                    temp[j[1]] = vis[j[0]] + j[2];
                }
            }
            vis = temp;
        }
        return vis[dst] == INT_MAX ? -1 : vis[dst];
    }
};
