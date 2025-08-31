class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r = (n*m)-1;

        while(l <= r){
            int mid = (l+r)/2;

            int row = mid / m;   // which row (divide by number of columns)
            int col = mid % m;   // which column (remainder within row)

            if(matrix[row][col] == target) return true;

            else if(matrix[row][col] < target) l = mid + 1;
            else r = mid-1;
        }

        return false;
    }
};