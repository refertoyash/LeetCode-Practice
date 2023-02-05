class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char,int> mp;
        for(auto &v: p) mp[v]++;
        
        int i = 0, j = 0;
        map<char,int> curr;
        while(j<s.size()){
            curr[s[j]]++;
            if(j-i+1<p.size()) j++;
            else{
                if(curr==mp) ans.push_back(i);
                curr[s[i]]--;
                if(curr[s[i]]==0) curr.erase(s[i]);
                i++,j++;
            }
        }
        return ans;
        
    }
};