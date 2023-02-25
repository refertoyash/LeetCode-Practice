class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            vector<int> lm(n);
            lm[0] = height[0];
            for (int i = 1; i < n; i++)
            {
                lm[i] = max(height[i], lm[i - 1]);
            }
            vector<int> rt(n);
            rt[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                rt[i] = max(height[i], rt[i + 1]);
            }

            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += min(lm[i], rt[i]) - height[i];
            }
            return ans;
        }
};