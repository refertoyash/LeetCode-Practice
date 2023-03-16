class Solution {
public:
    bool isvalid(int i, int j, int n, int m, vector<vector<bool>> &vis){
        return (i>=0 && i<n && j>=0 && j<m && !vis[i][j]);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initial = image[sr][sc];
        
        //Applying BFS
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n+1,vector<bool>(m,false));
        q.push({sr,sc});
        vis[sr][sc] = true;
        
        while(!q.empty()){
            int currx = q.front().first;
            int curry = q.front().second;
            q.pop();
            image[currx][curry] = color;
            
            //all neighbours of currx and curry
            if(isvalid(currx-1,curry,n,m,vis) && image[currx-1][curry]==initial){
                q.push({currx-1,curry});
                vis[currx-1][curry] = true;
            }
            
            if(isvalid(currx+1,curry,n,m,vis) && image[currx+1][curry]==initial){
                q.push({currx+1,curry});
                vis[currx+1][curry] = true;
            }
            
            if(isvalid(currx,curry-1,n,m,vis) && image[currx][curry-1]==initial){
                q.push({currx,curry-1});
                vis[currx][curry-1] = true;
            }
            
            if(isvalid(currx,curry+1,n,m,vis) && image[currx][curry+1]==initial){
                q.push({currx,curry+1});
                vis[currx][curry+1] = true;
            }
            
        }
        
        return image;
    }
};