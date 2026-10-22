class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false, y = false, z = false;
        for(auto i : triplets) {
            if(i[0] > target[0] || i[1] > target[1] || i[2] > target[2])continue;
            if(i[0] == target[0])x = true;
            if(i[1] == target[1])y = true;
            if(i[2] == target[2])z = true;
        }
        if(x && y && z)return true;
        return false;
    }
};
