class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &arr)
        {
            vector<vector < int>> ans;

            sort(arr.begin(), arr.end());
            int l = arr[0][0];
            int r = arr[0][1];

            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i][0] > r)
                {
                   	//new beginning
                    ans.push_back({l,r});
                    l = arr[i][0];
                    r = arr[i][1];
                }
                else
                {
                    r = max(r, arr[i][1]);
                }
            }
            ans.push_back({l,r});
            return ans;
        }
};