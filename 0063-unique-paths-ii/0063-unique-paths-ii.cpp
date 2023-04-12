class Solution
{
    public:
        int uniquePathsWithObstacles(vector<vector < int>> &obstacleGrid)
        {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            int dp[m + 1][n + 1];
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;

            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    if(obstacleGrid[i][j]==1) {dp[i][j] = 0; continue;}
                    if (i - 1 >= 0) dp[i][j] = dp[i - 1][j];
                    if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
                }
            }
            
            return dp[m - 1][n - 1];
        }
};