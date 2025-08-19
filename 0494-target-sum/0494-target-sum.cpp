class Solution {
public:
    int findTotalWays(vector<int>& arr, vector<vector<int>>& dp, int i, int s,
                      int target, int total_sum) {

        // If target is reached, return 1
        if (s == target && i == arr.size())
            return 1;

        // If all elements are processed and
        // target is not reached, return 0
        if (i >= arr.size())
            return 0;

        // If the result for the current state (i, s +
        // total_sum) has already been computed,
        // return it from the DP table to avoid redundant
        // calculations.
        if (dp[i][s + total_sum] != -1)
            return dp[i][s + total_sum];

        // Return total count of two cases
        // 1. Consider current element and add it to current sum
        // target
        // 2. Consider current element and subtract it from
        // current sum.
        return dp[i][s + total_sum] =
                   findTotalWays(arr, dp, i + 1, s + arr[i], target,
                                 total_sum) +
                   findTotalWays(arr, dp, i + 1, s - arr[i], target, total_sum);
    }
    int findTargetSumWays(vector<int>& A, int target) {
        int n = A.size();
        int total_sum = 0;
        for (int i = 0; i < A.size(); i++)
            total_sum += A[i];

        vector<vector<int>> dp(n, vector<int>(2 * total_sum + 1, -1));
        return findTotalWays(A, dp, 0, 0, target, total_sum);
    }
};