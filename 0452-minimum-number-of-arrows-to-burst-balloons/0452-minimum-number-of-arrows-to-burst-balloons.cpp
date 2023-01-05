class Solution
{
    public:
        int findMinArrowShots(vector<vector < int>> &points)
        {   
            vector<pair<int,int>> arr;
            for(auto &v: points){
                arr.push_back({v[0],v[1]});
            }
            
            sort(arr.begin(), arr.end());
            
            int ans = 0, min_right = INT_MAX;

            for (auto &v: arr)
            {
                if (v.first > min_right)
                {
                   	//not overlapping
                    ans++;
                    min_right = v.second;
                }
                else
                {
                   	//overlapping
                    min_right = min(min_right, v.second);
                }
            }
            return ans + 1;
        }
};