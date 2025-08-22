class Solution {
public:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }

    int f(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j)
            return 0;
        if (isPalindrome(s, i, j))
            return 0; // ? No cut needed if whole substring is palindrome

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k <= j - 1; k++) {
            if (isPalindrome(s, i, k)) { // only cut if left side is palindrome
                int temp = 1 + f(s, k + 1, j, dp);
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }

    int minCut(string& s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(s, 0, n - 1, dp);
    }
};