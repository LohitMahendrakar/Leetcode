class Solution {
public:

    // BFS function to mark all connected '1's (land) from a starting cell
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;   // mark current cell as visited
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row, col});

        // Directions: up, right, down, left
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Explore all 4 neighbors
            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check boundaries + land cell + not visited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;      // mark as visited
                    q.push({nrow, ncol});     // push neighbor into queue
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0; // number of islands
        vector<vector<int>> vis(n, vector<int>(m, 0)); // visited matrix

        // Traverse each cell
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                // If it's land ('1') and not visited -> new island found
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;                  // increment island count
                    bfs(row, col, vis, grid); // BFS to mark whole island
                }
            }
        }

        return cnt; // return total number of islands
    }
};
