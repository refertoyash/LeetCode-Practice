class Solution
{
    public:
        string getPermutation(int n, int k)
        {
            string ans = "";
            for (int i = 0; i < n; i++)
            {
                ans.push_back(i + 1 + '0');
            }
            if (k == 1) return ans;
            k--;
            while (next_permutation(ans.begin(), ans.end()))
            {
                k--;
                if (k == 0) break;
            }
            return ans;
        }
};