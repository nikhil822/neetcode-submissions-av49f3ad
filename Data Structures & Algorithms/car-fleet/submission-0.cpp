class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n = position.size();
        for(int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        stack<double> st;
        double mx = -1.0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            double time = (float(target - v[i].first) / v[i].second);
            
            if(st.empty()){
                st.push(time);
            } else if(mx < time){
                while(!st.empty() && mx < time) {
                    st.pop();
                }
                ans++;
            }
            mx = max(mx, time);
            st.push(time);
        }
        return ++ans;
    }
};