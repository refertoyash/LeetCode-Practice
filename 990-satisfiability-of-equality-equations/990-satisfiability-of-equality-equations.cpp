class Solution
{
    public:
        int N = 510;
    bool ispath(int start, int end, vector<char> adj[], vector<bool> &visited)
    {
        if (end == start) return true;
        visited[start] = true;
        for (auto it: adj[start])
            if (!visited[it])
                if (ispath(it, end, adj, visited))
                    return true;
        return false;
    }

    bool equationsPossible(vector<string> &equations)
    {
       	//applying concept of dfs
        vector<char> adj[N];
        for (int i = 0; i < equations.size(); i++)
        {
            if (equations[i][1] == '=')
            {
                adj[equations[i][0]].push_back(equations[i][3]);
                adj[equations[i][3]].push_back(equations[i][0]);
            }
        }
        for (int i = 0; i < equations.size(); i++)
        {
            vector<bool> visited(N, false);
            if (equations[i][1] == '!')
            {
                if (ispath(equations[i][0], equations[i][3], adj, visited)) return false;
            }
        }
        return true;
    }
};