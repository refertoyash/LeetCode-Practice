class Solution
{
    public:
        bool checkSubarraySum(vector<int> &nums, int k)
        {
            long long sum = 0;
            int n = nums.size();

            map<int, int> mp;	//mod value @ this id
           	//BASE CASE
            for (int i = 0; i < n; i++)
            {
                sum += nums[i];
                if (sum % k == 0 && i > 0) return true;
            }
           	//BASE CASE
            sum = 0;
            for (int i = 0; i <n; i++)
            {
                sum += nums[i];
                if (mp[sum % k] == 0) mp[sum % k] = i + 1;
                else
                {
                    if (i + 1 - mp[sum % k] >= 2) return true;
                }
            }

            return false;
        }
};