class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        ans.reserve(n * m);  // reserve space, but size is 0

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.push_back(mat[i][j]);
            }
        }

        sort(ans.begin(), ans.end()); // sort all elements
        return ans[k - 1];
    }
};