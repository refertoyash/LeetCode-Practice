class Solution
{
    public:
        int minCost(string colors, vector<int> &neededTime)
        {
            int ans = 0;
            int n = colors.size();
            for (int i = 0; i < n;)
            {
                int maxi = -1;
                int ct = 0;
                char c = colors[i];
                int sum = 0;
                while (i < n && colors[i] == c)
                {
                    maxi = max(maxi, neededTime[i]);
                    sum += neededTime[i];
                    i++, ct++;
                }
                if (ct >= 2) ans = ans + sum - maxi;
            }
            return ans;
        }
};