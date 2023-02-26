class Solution
{
    public:
        vector<vector < int>> ans;
    void func(int id, vector<int> &arr, int left, vector<int> &temp)
    {

        if (left < 0) return;
        if (left == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = id; i < arr.size(); i++)
        {
            if (i > id && arr[i] == arr[i - 1]) continue;
            temp.push_back(arr[i]);
            func(i + 1, arr, left - arr[i], temp);
            temp.pop_back();
        }
        
    }

    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        func(0, candidates, target, temp);
        return ans;
    }
};