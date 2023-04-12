class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        //dp[i][j] = best ans @ (i,j) from (0,0)
        
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        memset(dp,1e4,sizeof(dp));
        dp[0][0] = grid[0][0];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0) continue;
                if(i-1>=0) dp[i][j] = dp[i-1][j];
                if(j-1>=0) dp[i][j] = min(dp[i][j-1],dp[i][j]);
                dp[i][j] += grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};