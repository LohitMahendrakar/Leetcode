class Solution {
public:

    int f(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){

        
        if(m >= matrix.size()) return 1e9;
        if(n<0 || n>=matrix[0].size()) return 1e9;
        if(m == matrix.size()-1) return matrix[m][n];

        if(dp[m][n] != -1) return dp[m][n];

        int ld = f(m+1, n-1, matrix, dp);
        int dwn = f(m+1, n, matrix, dp);
        int rd = f(m+1, n+1, matrix, dp);

        return dp[m][n] = matrix[m][n] + min({ld, dwn, rd});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        int ans = INT_MAX;
        for(int i=0; i<matrix.size(); i++){
            ans = min(ans, f(0, i, matrix, dp));
        }

        return ans;
    }
};