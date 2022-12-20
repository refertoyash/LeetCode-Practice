class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            vector<int> ans;
            map<int, int> mp;
            for (auto &v: nums) mp[v]++;
            multimap<int, int> freq;
            for (auto &v: mp)
            {
                freq.insert({ -v.second,
                    v.first });
            }

            for (auto &v: freq)
            {
                ans.push_back(v.second);
                k--;
                if (k == 0) break;
            }
            return ans;
        }
};