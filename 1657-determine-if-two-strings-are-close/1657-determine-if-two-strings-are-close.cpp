class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        map<char,int> m1,m2; int n = s1.size();
        set<char> st1,st2;
        for(int i = 0; i<n; i++) m1[s1[i]]++,m2[s2[i]]++,st1.insert(s1[i]),st2.insert(s2[i]);
        if(st1!=st2) return false;
        map<int,int> f1, f2;
        for(auto &v: m1) f1[v.second]++;
        for(auto &v: m2) f2[v.second]++;
        return (f1==f2);
    }
};