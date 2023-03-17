class Solution {
public:
    bool isboundary(int i, int j, int n, int m){
        return (i==0 || i==n-1 || j==0 || j==m-1);
    }
    
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<bool>> &vis){
        vis[i][j] = true;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        int n = board.size();
        int m = board[0].size();
        
        for(int p = 0; p<4; p++){
            int x = i + delrow[p];
            int y = j + delcol[p];
            if(x>=0 && y>= 0 && x<n && y<m && !vis[x][y] && board[x][y]=='O'){
              dfs(x,y,board,vis);
            }    
        }
    }
    
    void solve(vector<vector<char>>& board) {
         // boundary element pe dfs laga do (travell island of 0 whose 1 cell is @boundary)
         // Only these will be left as 0 all other as X
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j]=='O' && isboundary(i,j,n,m)) dfs(i,j,board,vis);
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};