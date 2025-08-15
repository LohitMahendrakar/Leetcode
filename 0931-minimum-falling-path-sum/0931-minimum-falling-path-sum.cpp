class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();

        vector<vector<int>> dp(m, vector<int>(m));
        for(int i=0; i<m; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<m; i++){
            for(int j=0; j<m; j++){
                if(j<=0) dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                else if(j>=m-1) dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j];

                else{
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]}) + matrix[i][j];
                }
            }
        }

        int ans = 1e9;
        for(int j=0; j<m; j++){
            ans = min(ans, dp[m-1][j]);
        }

        
        return ans;
    }
};