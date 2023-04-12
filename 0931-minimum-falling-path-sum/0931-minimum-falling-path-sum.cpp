class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = matrix[0][0];
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0) continue;
                if(i-1>=0)  dp[i][j] = dp[i-1][j];
                if(i-1>=0 && j-1>=0) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                if(i-1>=0 && j+1<m) dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
                dp[i][j]+=matrix[i][j];
            }
        }
        
        
        int ans = 1e8;
        for(int i = 0; i<m; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};