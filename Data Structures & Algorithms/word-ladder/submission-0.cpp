class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> freq;
        for(auto i : wordList) {
            freq[i]++;
        }
        queue<string> q;
        unordered_map<string, int> vis;
        q.push(beginWord);
        vis[beginWord] = 1;
        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            cnt++;
            for(int i = 0; i < sz; i++) {
                string temp = q.front();
                q.pop();
                if(temp == endWord)return cnt;
                for(int j = 0; j < temp.size(); j++) {
                    char ch = temp[j];
                    for(int k = 0; k < 26; k++) {
                        temp[j] = 'a' + k;
                        if(vis[temp] == 0 && freq[temp] > 0) {
                            q.push(temp);
                            vis[temp] = 1;
                        }
                    }
                    temp[j] = ch;
                }
            }
        
        }
        return 0;
    }
};
