class Solution
{
    public:
        vector<int> findErrorNums(vector<int> &nums)
        {
            vector<int> ans;
            map<int, int> mp;
            set<int> st;
            for (int i = 1; i <= nums.size(); i++) st.insert(i);
            for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;
            for (auto &v: mp)
                if (v.second > 1) ans.push_back(v.first);
            for (auto &v: nums)
            {
                if (st.find(v) != st.end()) st.erase(v);
            }
            ans.push_back(*st.begin());
            return ans;
        }
};