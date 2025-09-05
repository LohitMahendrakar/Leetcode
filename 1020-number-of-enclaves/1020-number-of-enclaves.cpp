class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& mat, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j] == 0) return;

        mat[i][j]=0;

        dfs(i+1, j, mat, n, m);
        dfs(i-1, j, mat, n, m);
        dfs(i, j+1, mat, n, m);
        dfs(i, j-1, mat, n, m);
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1 && (i==0 || j==0 || i==n-1 || j==m-1)){
                    dfs(i,j,mat,n,m);
                }
            }
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1) cnt++;
            }
        }

        return cnt;
    }
};