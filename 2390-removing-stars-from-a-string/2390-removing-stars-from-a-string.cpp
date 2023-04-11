class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int ct  = 0 ;
        for(int i = s.size()-1; i>=0 ;i--){
            if(s[i]=='*') ct++;
            else if(ct>0) ct--;
            else ans.push_back(s[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};