class Solution
{
    public:
    vector<vector < int>> ans;
    void backtrack(vector<int> &temp, vector<int> &nums, int id)
    {
        ans.push_back(temp);

        for (int i = id; i < nums.size(); i++)
        {
            if(i>id && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);	//expolre all possibility with this
            backtrack(temp, nums, i + 1);
            temp.pop_back();	//
        }
    }

    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        backtrack(temp,nums,0);
        return ans;
    }
};