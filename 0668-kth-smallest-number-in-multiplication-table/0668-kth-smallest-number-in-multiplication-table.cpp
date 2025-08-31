class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> ans;
        ans.reserve(n*m);
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                ans.push_back(i*j);
            }
        }

        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};