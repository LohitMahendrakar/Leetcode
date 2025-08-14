class Solution {
public:
    int f(int m, int n, vector<vector<int>> &dp, vector<vector<int>>& ob) {
        // Out of bounds
        if (m < 0 || n < 0) return 0;

        // Obstacle cell
        if (ob[m][n] == 1) return 0;

        // Start cell
        if (m == 0 && n == 0) return 1;

        // Memoization
        if (dp[m][n] != -1) return dp[m][n];

        int right = f(m, n - 1, dp, ob);
        int down  = f(m - 1, n, dp, ob);

        return dp[m][n] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If start or end cell is an obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp, obstacleGrid);
    }
};
