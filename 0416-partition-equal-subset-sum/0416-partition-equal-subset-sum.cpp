class Solution {
public:
    // Recursive function to check subset sum with memoization
    bool f(vector<int>& arr, int sum, vector<vector<int>>& dp, int n){
        // Base Conditions
        if(sum == 0) return true;    // found a subset
        if(n == 0)    return false;  // no elements left

        // If already computed, return stored answer
        if(dp[n][sum] != -1) return dp[n][sum];

        if(arr[n-1] <= sum){
            // Include the element OR exclude it
            bool include = f(arr, sum - arr[n-1], dp, n-1);
            bool exclude = f(arr, sum, dp, n-1);
            return dp[n][sum] = include || exclude;
        }
        else{
            // Element too big → cannot include, only exclude
            return dp[n][sum] = f(arr, sum, dp, n-1);
        }
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size();

        // Calculate total sum
        int sum = 0;
        for(int x : arr) sum += x;

        // If sum is odd → cannot divide into two equal subsets
        if(sum % 2 != 0) return false;

        int target = sum / 2;

        // Create dp initialized with -1 (unvisited)
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

        // Check if subset with sum = target exists
        return f(arr, target, dp, n);
    }
};