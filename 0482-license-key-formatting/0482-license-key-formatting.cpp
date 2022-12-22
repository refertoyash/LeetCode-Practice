class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        for(int i = s.size()-1; i>=0; ){
            for(int j = 0; j<k && i>=0;){
             if(s[i]=='-') {i--;continue;}
             if(s[i]>='a' && s[i]<='z') s[i]^=(1<<5);
             ans.push_back(s[i]);
             i--,j++;
            }
            while(i>=0 && s[i]=='-') i--;
            if(i>=0) ans.push_back('-');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};