class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> m;
        int res = 0, i = 0, j = 0, mxFreq = 0;
        while(j < n) {
            m[s[j]]++;
            mxFreq = max(mxFreq, m[s[j]]);
            while((j - i + 1) - mxFreq > k) {
                m[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
