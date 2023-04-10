class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i]=='(' || s[i] =='{' || s[i]=='[') st.push(s[i]);
            if(s[i]==')' || s[i] =='}' || s[i]==']'){
                if(st.empty()) return false;
                if(s[i]==')' && st.top()!='(') return false;
                if(s[i]=='}' && st.top()!='{') return false;
                if(s[i]==']' && st.top()!='[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};