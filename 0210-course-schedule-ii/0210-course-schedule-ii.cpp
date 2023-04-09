class Solution {
public:
    bool dfs_ispossible(int node, vector<int> adj[], vector<int> &vis, vector<int> &path) {
        vis[node] = 1;
        
        for (auto child : adj[node]) {
            if (vis[child] == 1) {
                return false; // cycle detected
            }
            if (vis[child] == 0) {
                if (!dfs_ispossible(child, adj, vis, path)) {
                    return false;
                }
            }
        }
        vis[node] = 2;
        path.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
         
        for(auto &v: prerequisites){
           adj[v[1]].push_back(v[0]);
        }
        
        vector<int> vis(numCourses, 0); 
        vector<int> path;
        
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs_ispossible(i, adj, vis, path)) {
                    return {}; 
                }
            }
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
