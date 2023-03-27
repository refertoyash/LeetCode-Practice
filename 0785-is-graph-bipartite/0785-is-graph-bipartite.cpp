class Solution
{
    public:
        bool dfs(int node, int col, vector<int> &color, vector<vector< int>> &graph)
        {
            color[node] = col;
            for (auto &neighbour: graph[node])
            {
                if (color[neighbour] == -1)
                {
                   	//first time coloring
                    if (!dfs(neighbour, !col, color, graph)) return false;
                }
                else if (color[neighbour] == col) return false;
            }
            return true;
        }

    bool isBipartite(vector<vector < int>> &graph) {
        int v = graph.size();
        vector<int> color(v+2,-1);
        
        for(int i = 0; i<v; i++){
           if(color[i]==-1){
               if(!dfs(i,0,color,graph)) return false;
               // 0 specifying initial color with which i wanna color start node
           }
        }
        return true;
    }
};