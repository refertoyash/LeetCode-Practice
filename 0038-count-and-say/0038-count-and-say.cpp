class Solution
{
    public:
        string countAndSay(int n)
        {
            if (n == 1) return "1";
            string ans = "";
            string s = countAndSay(n - 1);
            for (int i = 0; i < s.size();)
            {
                char curr = s[i];
                int ct = 0;
                while (s[i] == curr) ct++, i++;
                ans.push_back(ct + '0');
                ans.push_back(s[i - 1]);
            }
            return ans;
        }
};