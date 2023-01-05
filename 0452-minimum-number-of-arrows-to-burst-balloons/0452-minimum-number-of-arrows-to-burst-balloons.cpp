class Solution
{
    public:
        int findMinArrowShots(vector<vector < int>> &arr)
        {   
             sort(arr.begin(),arr.end());
            int n = arr.size();
            int ans = 0, min_right = INT_MAX;
            
            for(auto &v: arr){
                if(v[0]>min_right){
                    //not overlapping
                    ans++;
                    min_right = v[1];
                }
                else{
                    //overlapping
                    min_right = min(min_right,v[1]);
                }
            }
            return ans+1;
        }
};