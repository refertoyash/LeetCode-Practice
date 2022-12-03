class Solution
{
    public:
        string frequencySort(string s)
        {
            map<char, int> mp;
            for (int i = 0; i < s.size(); i++) mp[s[i]]++;
            s.clear();
            multimap<int, char> freq;

            for (auto &v: mp) freq.insert({ -v.second,v.first });
            
            for (auto &v: freq){
                int k = -v.first;
                while (k--) s.push_back(v.second);
            }
            
            return s;
        }
};