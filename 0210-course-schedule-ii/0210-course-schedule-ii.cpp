class Solution {
public:
    static bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathvis, vector<int> &path){
          vis[node]  = true, pathvis[node] = true;

        for(auto &child: adj[node]){
              if(!vis[child]){
                  if(dfs(child,adj,vis,pathvis,path)) return true;
              }
              else if(pathvis[child]) return true;
          }
          pathvis[node] = false;
          path.push_back(node);
          return false;
    }
    
    static vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> path;
        vector<bool> vis(n,false);
        vector<bool> pathvis(n,false);
        vector<int> adj[n];
        
        for(auto &v: prerequisites){
           adj[v[1]].push_back(v[0]);
        }
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,path)) return {};
            }
        }
        reverse(path.begin(),path.end());
        if(path.size()==n) return path;
        return {};
    }
};
