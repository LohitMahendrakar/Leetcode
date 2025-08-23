class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));

        int m = 0;
        while(dp[m][k] < n) {
            m++;
            for(int e=1; e<=k; e++) {
                dp[m][e] = dp[m-1][e-1] + dp[m-1][e] + 1;
            }
        }
        return m;
    }
};