class Solution
{
    public:
        bool isposs(int i, int j, int n, int m, vector<vector < bool>> &vis)
        {
            return (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j]);
        }

    void bfs(int i, int j, vector<vector < int>> &grid, vector< vector< bool >> &vis, vector< vector< int>> &min_time)
    {
        queue<pair<int, int>> q;
        q.push({ i,
            j });
        vis[i][j] = true;
        int n = grid.size(), m = grid[0].size();
        int ct = 1;

        while (!q.empty())
        {

            int k = q.size();
            while (k--)
            {
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                if (isposs(cx - 1, cy, n, m, vis) && grid[cx - 1][cy] != 0){
                    q.push({ cx - 1, cy });
                    vis[cx - 1][cy] = true;
                    min_time[cx - 1][cy] = min(min_time[cx - 1][cy], ct);
                }
                if (isposs(cx + 1, cy, n, m, vis) && grid[cx + 1][cy] != 0){
                    q.push({ cx + 1,cy });
                    vis[cx + 1][cy] = true;
                    min_time[cx + 1][cy] = min(min_time[cx + 1][cy], ct);
                }
                if (isposs(cx, cy + 1, n, m, vis) && grid[cx][cy + 1] != 0){
                    q.push({ cx,cy + 1 });
                    vis[cx][cy + 1] = true;
                    min_time[cx][cy + 1] = min(min_time[cx][cy + 1], ct);
                }
                if (isposs(cx, cy - 1, n, m, vis) && grid[cx][cy - 1] != 0){
                    q.push({ cx,cy - 1 });
                    vis[cx][cy - 1] = true;
                    min_time[cx][cy - 1] = min(min_time[cx][cy - 1], ct);
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