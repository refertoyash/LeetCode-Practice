const long long mod = 1e9 + 7;

class Solution
{

    public:
        int getways(int n, int k, int target, vector<vector < int>> &dp)
        {
           	//currently selecting for xth dice
           	//Memoization
            if (n == 0)
            {
                if (target == 0) return 1;
                return 0;
            }

            if (target < 0) return 0;

            if (dp[n][target] != -1) return dp[n][target] % mod;
            int ans = 0;
            for (int i = 1; i <= k; i++)
            {
                if (i <= target) ans = (ans % mod + getways(n - 1, k, target - i, dp) % mod) % mod;
            }
            return dp[n][target] = ans % mod;
        }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector < int>> dp(32, vector<int> (1002, -1));
        int a = getways(n, k, target, dp);
        return a;
    }
};