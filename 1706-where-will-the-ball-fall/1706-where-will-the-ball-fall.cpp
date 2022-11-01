class Solution
{
    public:
        int nextcol(int i, int j, int n, int m, vector<vector < int>> &arr)
        {   
            if(i<0 || j<0) return -1;
            if (i == n - 1){
                if(arr[i][j] == 1){
                    if (j + 1 < m && arr[i][j + 1] == 1) return j + 1;
                    return -1;
                }
                else
                {
                    if (j - 1 >= 0 && arr[i][j - 1] == -1) return j - 1;
                    return - 1;
                }
            }
            
            int ans;
            if (j + 1 < m && arr[i][j] == 1 && arr[i][j + 1] == 1) ans = nextcol(i + 1, j + 1, n, m, arr);
            else if (j - 1 >= 0 && arr[i][j] == -1 && arr[i][j - 1] == -1) ans = nextcol(i + 1, j - 1, n, m, arr);
            else ans = nextcol(-1,-1,n,m,arr);
            return ans;
        }

    vector<int> findBall(vector<vector < int>> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        int m = arr[0].size();
        for (int j = 0; j < m; j++)
        {   bool np = false;
            for(int p = 0; p<n; ){
                int q = j;
                while(true){
                    if(q+1<m && arr[p][q]==1 && arr[p][q+1]==1) {p++; q++;}
                    else if(q-1>=0 &&  arr[p][q]==-1 && arr[p][q-1]==-1) {p++; q--;}
                    else np = true;
                    if(np) break;
                    if(p>=n) break;
                }
                if(np) break;
                else ans.push_back(q);
            }
            if(np) ans.push_back(-1);
        }
        return ans;
    }
};