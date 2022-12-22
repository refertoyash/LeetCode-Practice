class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans  = 0;
        for(auto &v: nums) ans = (ans^v);
        return ans;
    }
};