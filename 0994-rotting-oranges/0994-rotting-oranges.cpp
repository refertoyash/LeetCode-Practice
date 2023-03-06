class Solution
{
    public:
        int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        bool isposs(int i, int j, int n, int m, vector<vector < bool>> &vis)
        {
            return (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j]);
        }

    void bfs(int i, int j, vector<vector < int>> &grid, vector< vector< bool >> &vis, vector< vector< int>> &min_time)
    {
        queue<pair<int, int>> q;
        q.push({ i, j });
        vis[i][j] = true;
        int n = grid.size(), m = grid[0].size();
        int ct = 1;

        while (!q.empty())
        {

            int k = q.size();
            //inner loop here works in some kind as a "LEVEL",
            while (k--)
            {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                
                for(int i = 0; i<4; i++){
                  int r = cx + dir[i][0];
                  int c = cy + dir[i][1];
                  if(isposs(r,c,n,m,vis) && grid[r][c]!=0){
                    q.push({ r ,c });
                    vis[r][c] = true;
                    min_time[r][c] = min(min_time[r][c], ct);
                  }
                }
                
            }
            
            ct++;
        }
    }

    int orangesRotting(vector<vector < int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector < int>> min_time(n, vector<int> (m, INT_MAX));
       	//every cell will store minimum time to get rotten
       	// already rotten marked as 0 sec, empty and other are marked as INT_MAX

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2) min_time[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    vector<vector < bool>> vis(n, vector<bool> (m, false));
                    bfs(i, j, grid, vis, min_time);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] != 0 && min_time[i][j] == INT_MAX) return -1;
                if (grid[i][j] != 0) ans = max(ans, min_time[i][j]);
            }
        }
        return ans;
    }
};