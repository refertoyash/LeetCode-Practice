class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {
            map<int, vector < int>> mp;
            int n = nums.size();
            for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);

            for (auto &v: mp)
            {
                for (int i = 0; i < v.second.size() - 1; i++)
                {
                    if (v.second[i + 1] - v.second[i] <= k) return true;
                }
            }

            return false;
        }
};