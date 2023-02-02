class Solution {
public:
    
    bool cmp(string s1, string s2,map<char,int> &idx){
        //kya s1,s2 se pahle dictionary me aayega ??
        for(int i = 0; i<min(s1.size(),s2.size()); i++){
            if(s1[i]==s2[i]) continue;
            if(idx[s1[i]] > idx[s2[i]]) return false;
            else return true;
        }
        
        if(s1.size()==s2.size()) return true;
        if(s1.size()>s2.size()) return false;
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> idx;
        for(int i = 0; i<(int)order.size(); i++){
            idx[order[i]] = i+1;
        }
        
        for(int i = 0; i<(int)words.size()-1; i++){
            if(!cmp(words[i],words[i+1],idx)) return false;
        }
        
        return true;
    }
};