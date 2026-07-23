class Solution {
public:
    bool check(string temp, unordered_map<char, int> m) {
        for(auto i : temp) {
            m[i]--;
            if(m[i] == 0)m.erase(i);
        }
        return m.size() == 0;
    }
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        unordered_map<char, int> m;
        for(auto i : s1) {
            m[i]++;
        }
        if(l1 > l2)return false;
        int i = 0, j = 0;
        while(j < l2) {
            if(j - i + 1 < l1) {
                j++;
            }
            if(j - i + 1 == l1) {
                string temp = s2.substr(i, j - i + 1);
                if(check(temp, m)) {
                    return true;
                }
                i++;
             }
        }
        return false;
    }
};
