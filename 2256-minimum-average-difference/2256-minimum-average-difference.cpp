class Solution {
public:
    int minimumAverageDifference(vector<int>& nums){
        vector<long long> psum; 
        vector<long long> ssum;
        int n = nums.size();
        if(n==1) return 0;
        
        psum.push_back(nums[0]);
        ssum.push_back(nums[n-1]);
        for(int i = 1; i<n; i++) psum.push_back(psum.back()+nums[i]);
        for(int i = n-2; i>=0; i--) ssum.push_back(ssum.back()+nums[i]);
        reverse(ssum.begin(),ssum.end());
        ssum.push_back(0);
        
        int id = -1;
        long long mini = 1e18;
        for(int i = n-1; i>=0;i--){
            int one = psum[i]/(i+1);
            int se;
            if(i+1!=n) se = ssum[i+1]/(n-(i+1));
            else se = 0;
            int p = abs(one-se);
            if(p<=mini) mini=p,id=i;
        }
        return id;
        
    }
};