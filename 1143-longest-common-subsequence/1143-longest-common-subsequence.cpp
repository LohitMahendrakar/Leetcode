class Solution {
public:
    int f(string &s1, string &s2, int n, int m, vector<vector<int>>& dp){
        if(n < 0 || m < 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s1[n] == s2[m]){
            dp[n][m] =  1 + f(s1, s2, n-1, m-1, dp);
        }
        
        else{
            dp[n][m] = max(f(s1, s2, n, m-1, dp), f(s1, s2, n-1, m, dp));
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(s1, s2, n-1, m-1, dp);
    }
};