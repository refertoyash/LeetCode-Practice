class Solution
{
    public:
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