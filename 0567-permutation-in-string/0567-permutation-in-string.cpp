class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        //sliding window
        int i = 0, j = 0;
        map<char,int> one;
        for(auto &v: s1) one[v]++;
        map<char,int> curr;
        
        while(j<m){
            curr[s2[j]]++;
            if(j-i+1<n) j++;
            else{
                if(one==curr) return true;
                //remove previous
                curr[s2[i]]--;
                if(curr[s2[i]]==0) curr.erase(s2[i]);
                //slide
                i++,j++;
            }
        }
        
        return false;
    }
};