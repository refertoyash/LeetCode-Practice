class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());
            int closest = 1e9;
            for (int i = 0; i < nums.size(); i++)
            {
                int low = i + 1, high = nums.size() - 1;
                while (low < high)
                {
                    int csum = nums[low] + nums[high] + nums[i];
                    if (csum == target) return csum;
                    if (abs(target - csum) < abs(target - closest))
                    {
                        closest = csum;
                    }
                    if (csum > target) high--;
                    else low++;
                }
            }
            return closest;
        }
};