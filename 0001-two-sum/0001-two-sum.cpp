class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        vector<int> ans(2);
        map<int,vector<int>> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto &v: mp){
            int nt = target - v.first;
            if(nt==v.first){
                if(mp[nt].size()>=2){
                    ans[0] = mp[nt][0];
                    ans[1] = mp[nt][1];
                    return ans;
                }
            }
            else if(mp[nt].size()!=0){
                ans[0] = v.second[0];
                ans[1] = mp[nt][0];
                return ans;
            }
        }
        
        return ans;
    }
};