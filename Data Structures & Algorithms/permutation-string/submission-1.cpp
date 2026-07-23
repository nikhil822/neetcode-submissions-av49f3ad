class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if(l1 > l2)return false;
        vector<int> need(26, 0), window(26, 0);
        for(auto i : s1) {
            need[i - 'a']++;
        }
        int i = 0, j = 0;
        while(j < l2) {
            window[s2[j] - 'a']++;
            if(j - i + 1 == l1) {
                if(need == window)return true;
                window[s2[i] - 'a']--;
                i++;
             }
             j++;
        }
        return false;
    }
};
