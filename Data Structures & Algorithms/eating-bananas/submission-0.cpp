class Solution {
public:
    int check(int mid, vector<int>& piles, int h) {
        int sum = 0, t = 0;
        for(int i = 0; i < piles.size(); i++) {
            t += piles[i] / mid + ((piles[i] % mid ) > 0);
        }
        return t <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid, piles, h)) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return low;
    }
};
