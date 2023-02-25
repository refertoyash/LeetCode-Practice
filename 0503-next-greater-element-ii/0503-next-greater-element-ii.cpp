class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            int n = nums.size();
            stack<int> st;
            for (int i = n - 1; i >= 0; i--)
            {
                st.push(nums[i]);
            }

            vector<int> ans;
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && st.top() <= nums[i]) st.pop();
                if (st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
                st.push(nums[i]);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};