class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            map<char, int> mp1;
            map<char, int> mp2;
            for (auto &v: s) mp1[v]++;
            for (auto &v: t) mp2[v]++;
            return mp1 == mp2;
        }
};