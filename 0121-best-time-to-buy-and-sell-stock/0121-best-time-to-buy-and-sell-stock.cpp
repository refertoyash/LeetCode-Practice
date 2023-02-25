class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int mx = 0;
            vector<int> right(prices.size());

            int temp = -1e5;
            int n = prices.size();
            for (int i = n - 1; i >= 0; i--)
            {
                right[i] = temp;
                temp = max(temp, prices[i]);
            }

            for (int i = 0; i < n; i++)
            {
                mx = max(mx, right[i] - prices[i]);
            }

            return mx;
        }
};