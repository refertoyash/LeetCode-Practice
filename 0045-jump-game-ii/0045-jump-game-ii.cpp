

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX);
        //dp[i] = i tak pahuchne  ke liye minimum kitne step
        dp[0] = 0;
        for(int i = 0; i<n; i++){
            int mini = 1e8;
            for(int j = i-1; j>=0; j--){
                if(nums[j] + j >= i) mini = min(mini,dp[j]);
            }
            dp[i] = min(dp[i],mini + 1);
        }
        return dp[n-1];
    }
};