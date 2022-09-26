  const int N = 502;
  vector<int> parent(N, 0);
  vector<int> siz(N, 0);

  class Solution
  {

      public:
          void make_set(int v)
          {
              parent[v] = v;
              siz[v] = 1;
          }

      int find_set(int v)
      {
          if (v == parent[v])
              return v;
          return parent[v] = find_set(parent[v]);
      }

      void union_sets(int a, int b)
      {
          a = find_set(a);
          b = find_set(b);
          if (a != b)
          {
              if (siz[a] < siz[b])
                  swap(a, b);
              parent[b] = a;
              siz[a] += siz[b];
          }
      }
      bool equationsPossible(vector<string> &equations)
      {
         	//making sets
          for (int i = 0; i < equations.size(); i++)
          {
              make_set(equations[i][0] - 'a');
              make_set(equations[i][3] - 'a');
          }
         	//join sets
          for (int i = 0; i < equations.size(); i++)
          {
              if (equations[i][1] == '=')
                  union_sets(equations[i][0] - 'a', equations[i][3] - 'a');
          }
         	//check if violating condition exist
          for (int i = 0; i < equations.size(); i++)
          {
              if (equations[i][1] == '!')
                  if (find_set(equations[i][0] - 'a') == find_set(equations[i][3] - 'a')) return false;
          }
          return true;
      }
  };