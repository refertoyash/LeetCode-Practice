class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            map<map<char, int>, vector< string>> mp;
            for (auto &v: strs)
            {
                map<char, int> temp;
                for (int i = 0; i < v.size(); i++) temp[v[i]]++;
                mp[temp].push_back(v);
            }
            vector<vector < string>> ans;
            for (auto &v: mp)
            {
                vector<string> temp;
                for (auto &str: v.second)
                    temp.push_back(str);
                ans.push_back(temp);
            }
            return ans;
        }
};