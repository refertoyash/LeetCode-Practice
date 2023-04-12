class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i-1>=0) dp[i][j] = dp[i-1][j];
                if(j-1>=0) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};