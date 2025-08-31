class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxRow = 0;
        int maxOnes = 0;

        for (int i = 0; i < n; i++) {
            int ones = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) ones++;
            }
            if (ones > maxOnes) {
                maxOnes = ones;
                maxRow = i;
            }
        }

        return {maxRow, maxOnes};
    }
};
