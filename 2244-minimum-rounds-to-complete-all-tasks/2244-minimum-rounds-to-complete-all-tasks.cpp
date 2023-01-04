class Solution {
public:
    int minimumRounds(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0; i<n; i++) mp[arr[i]]++;
        
        int op = 0;
        for(auto &v: mp){
          if(v.second%3==1 && v.second>1) op+= 2 + (v.second-4)/3;
          else if(v.second%3==2) op+= 1 + (v.second-2)/3;
          else if(v.second%3==0) op+= (v.second)/3;
          else return -1;
        }
        return op;
    }
};