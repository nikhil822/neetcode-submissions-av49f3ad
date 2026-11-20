class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n - 1; i++) {
            if(i > 0 && nums[i] == nums[i - 1])continue;
            int l = i + 1, r = n - 1;
            vector<int> temp;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0)r--;
                else if(sum < 0)l++;
                else {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    temp.clear();
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1])
                        l++;

                    while(l < r && nums[r] == nums[r + 1])
                        r--;
                }
                
            }
        }
        return res;
    }
};
