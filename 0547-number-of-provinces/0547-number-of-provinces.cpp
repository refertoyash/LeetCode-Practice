  class Solution
  {
      public:

          void dfs(int start, vector<vector < int>> &mat, vector< bool > &vis)
          {
              vis[start] = true;
              for (int i = 0; i < mat[start].size(); i++)
              {
                  if (mat[start][i] == 1 && !vis[i])
                  {
                      dfs(i, mat, vis);
                  }
              }
          }

      int findCircleNum(vector<vector < int>> &mat)
      {
          int n = mat.size();
          vector<bool> vis(n, false);
          int ans = 0;
          for (int i = 0; i < n; i++)
          {
              if (!vis[i])
              {
                  dfs(i, mat, vis);
                  ans++;
              }
          }
          return ans;
      }
  };