const int N = 3*1e4+5;
class Solution {
public:
  
    int kadanes(vector<int> &nums){
        int dp[N];
        dp[0] = nums[0];
        int n = nums.size();
        for(int i = 1; i<(int)nums.size(); i++){
           dp[i] = max(dp[i-1]+nums[i],nums[i]); 
           //purane ka hissa banega ya khud naya saaamrajya khada karega ???
        }

        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }


    int maxSubarraySumCircular(vector<int>& nums) {
        //max circular subarray sum = max(total sum - minsubarray sum,straight_max_sum); 
        int ans1 = kadanes(nums);
        if(ans1<0) return ans1;

        //dp[i] = min subarray sum ending at this index
        int n = nums.size();
        int sum = nums[0];
        nums[0]*=-1;

        for(int i = 1; i<(int)nums.size(); i++){
           sum+=nums[i];
           nums[i] = nums[i]*-1;
           //purane ka hissa banega ya khud naya saaamrajya khada karega ???
        }

        int min_sum = -1*kadanes(nums);
        // cout<<min_sum<<"\n";
        int ans2 = sum-min_sum;
        // cout<<ans1<<" "<<ans2<<"\n";
        return max(ans1,ans2);
    }
};