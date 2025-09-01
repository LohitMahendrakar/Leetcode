class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int n = grid.size();        // rows
        int m = grid[0].size();     // cols

        queue<pair<pair<int, int>, int>> q; 
        vector<vector<int>> vis(n, vector<int>(m, 0));  // visited matrix

        // Step 1: Push all initially rotten oranges into queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int tm = 0;
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};

        // Step 2: BFS traversal
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for (int i = 0; i < 4; i++) {
                int row = r + drow[i];
                int col = c + dcol[i];
                if (row >= 0 && row < n && col >= 0 && col < m &&
                    grid[row][col] == 1 && vis[row][col] == 0) {
                    q.push({{row, col}, t + 1});
                    vis[row][col] = 1;
                    grid[row][col] = 2;  // mark it rotten
                }
            }
        }

        // Step 3: Check if any fresh orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return tm;
    }
};
