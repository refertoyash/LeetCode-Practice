class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string temp = "";
        int n = str1.size();
        int m = str2.size();
        
        if(str1+str2== str2+str1)  return str1.substr(0,__gcd(n,m));
        
        return "";
    }
};