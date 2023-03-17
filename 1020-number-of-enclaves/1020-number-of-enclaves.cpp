class Solution {
public:
    bool isvalid(int i, int j, int n, int m){
        return (i>=0 && j>= 0 && i<n && j<m);
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid){
      vector<int> delrow = {-1, 0, 1, 0};
      vector<int> delcol = {0 , 1 , 0, -1};
      grid[i][j] = 0; //because of this line we are not using visited here
      int n = grid.size(); int m = grid[0].size();
      for(int p = 0; p<4; p++){
            int x = i+ delrow[p];
            int y = j+ delcol[p];
            if(isvalid(x,y,n,m) && grid[x][y]==1) dfs(x,y,grid);
      }
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        //count of all cell '1' which are not a part of island of boundary '1' cell
        
        //Logic: Sare boundary element pe dfs lagao (which are '1') and to all cell that you      reach mark it as zero
        //ans is number of cells that are still marked as '1'
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
               if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                   dfs(i,j,grid);
               }       
            }
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
          for(int j =0 ; j<m; j++)
                if(grid[i][j]==1) ans++;
        }
    
        return ans;
    }
};