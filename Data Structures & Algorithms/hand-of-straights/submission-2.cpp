class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for(auto i : hand) {
            m[i]++;
        }
        while(m.size() > 0) {
            int last = -1, freq = 0;
            for(auto &i : m) {
                freq++;
                if(last == -1) {
                    last = i.first;
                    --i.second;
                    if(i.second == 0)m.erase(i.first);
                    if(freq == groupSize)break;
                    continue;
                }
                if(i.first - last > 1)return false;
                last = i.first;
                --i.second;
                if(i.second == 0)m.erase(i.first);
                if(freq == groupSize)break;
            }
            if(freq < groupSize)return false;
        }
        return true;
    }
};

