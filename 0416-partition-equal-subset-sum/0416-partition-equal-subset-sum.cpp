class Solution {
public:
    bool isposs(int i, vector<int>&nums, int curr_sum1,  int total_sum, vector<vector<int>> &dp ){
        if(i==nums.size())  return false;
        if(2*curr_sum1==total_sum) return true;
        if(dp[i][curr_sum1]!=-1) return dp[i][curr_sum1];
        //if taken in sum1 or not taken in sum1
        bool a = isposs(i+1,nums,curr_sum1+nums[i], total_sum,dp) || isposs(i+1,nums,curr_sum1,total_sum,dp);
        return dp[i][curr_sum1] = a;
    }
    
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(int i = 0; i<nums.size(); i++) total_sum+=nums[i];
        vector<vector<int>> dp(nums.size(),vector<int>(50000,-1));
        //Logic: all possible sum generation, if any become 2*curr == total_sum true
        return isposs(0,nums,0,total_sum,dp);
    }
};