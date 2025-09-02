class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, 
            vector<vector<int>>& ans, int color, vector<vector<int>>& vis){
        int n = image.size();
        int m = image[0].size();

        int inicolor = image[sr][sc];
        ans[sr][sc] = color;
        vis[sr][sc] = 1;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = r + drow[i];
                int newc = c + dcol[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && image[newr][newc] == inicolor){
                    ans[newr][newc] = color;
                    vis[newr][newc] = 1;

                    q.push({newr,newc});
                }
            }
        }


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n, vector<int>(m,0));

        bfs(image,sr, sc, ans, color, vis);
        return ans;
    }
};