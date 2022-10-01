class Solution
{
    public:
        int num_ways(string s, int id, vector<int> &dp)
        {
            if (id < 0) return 1;
            if (id == 0)
            {
                if (s[id] != '0') return 1;
                else return 0;
            }
            if (dp[id] != -1) return dp[id];
            int case1 = 0, case2 = 0;
            if (s[id] > '0') case1 = num_ways(s, id - 1, dp);
            int num2;
            if (id >= 1)
            {
                string temp;
                temp.push_back(s[id]);
                temp.push_back(s[id - 1]);
                reverse(temp.begin(), temp.end());
                num2 = stoi(temp);
                if (num2 >= 10 && num2 <= 26) case2 = num_ways(s, id - 2, dp);
            }
            return dp[id] = case1 + case2;
        }
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 3, -1);
        int ans = num_ways(s, s.size() - 1, dp);
        return ans;
    }
};