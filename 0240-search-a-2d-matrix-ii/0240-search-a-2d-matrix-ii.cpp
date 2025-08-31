class Solution {
public:
    bool solve(vector<int>& arr, int x) {
        int l = 0;
        int r = arr.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) return true;
            if (arr[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();        // number of rows
        int m = mat[0].size();     // number of columns

        for (int i = 0; i < n; i++) {
            if (mat[i][0] <= x && mat[i][m - 1] >= x) {
                if (solve(mat[i], x)) return true;
            }
        }
        return false;
    }
};