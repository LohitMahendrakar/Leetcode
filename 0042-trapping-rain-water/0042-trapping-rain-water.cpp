class Solution {
public:
    int trap(vector<int>& a) { // a == height array
        int n = a.size();
        if (n == 0) return 0;

        int ans = 0;
        vector<int> lb(n), rb(n);

        // Left max array
        lb[0] = a[0];
        for (int i = 1; i < n; i++) {
            lb[i] = max(a[i], lb[i - 1]);
        }

        // Right max array
        rb[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rb[i] = max(a[i], rb[i + 1]);
        }

        // Water trapped
        for (int i = 1; i < n - 1; i++) {
            ans += min(lb[i], rb[i]) - a[i];
        }

        return ans;
    }
};
