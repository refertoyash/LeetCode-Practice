class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            vector<int> ans;
            vector<pair<int, int>> vp;
            for (int i = 0; i < arr.size(); i++)
            {
                vp.push_back({ abs(arr[i] - x),
                    arr[i] });
            }
            sort(vp.begin(), vp.end());

            for (auto &v: vp)
            {
                ans.push_back(v.second);
                if (ans.size() == k) break;
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
};