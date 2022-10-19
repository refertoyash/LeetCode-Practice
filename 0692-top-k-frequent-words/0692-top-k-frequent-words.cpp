class Solution
{
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            map<string, int> mp;
            for (int i = 0; i < words.size(); i++) mp[words[i]]++;
            multimap<int, string> freq;
            for (auto &v: mp)
            {
                freq.insert({ -v.second,
                    v.first });
            }
            vector<string> ans;
            for (auto &v: freq)
            {
                if (k == 0) return ans;
                ans.push_back(v.second);
                k--;
            }
            return ans;
        }
};