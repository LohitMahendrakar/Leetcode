class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while(l <= r){
            int k = (l+r) / 2; // k = mid
            long long hours = 0;

            for(auto p: piles){
                hours += (p + k - 1) / k;
            }

            if(hours <= h){
                ans = min(ans, k);
                r = k-1;
            }
            else l = k+1;
        }

        return ans;
    }
};