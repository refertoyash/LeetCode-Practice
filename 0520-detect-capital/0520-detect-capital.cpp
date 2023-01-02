class Solution
{
    public:
        bool iscase1(string &s, int n)
        {
            for (int i = 0; i < n; i++)
                if (!(s[i] >= 'A' && s[i] <= 'Z')) return false;
            return true;
        }

    bool iscase2(string &s, int n)
    {
        for (int i = 0; i < n; i++)
            if (!(s[i] >= 'a' && s[i] <= 'z')) return false;
        return true;
    }

    bool iscase3(string &s, int n)
    {
        if (!(s[0] >= 'A' && s[0] <= 'Z')) return false;
        for (int i = 1; i < n; i++)
            if (!(s[i] >= 'a' && s[i] <= 'z')) return false;
        return true;
    }

    bool detectCapitalUse(string s)
    {
        int n = s.size();
        if (iscase1(s, n) || iscase2(s, n) || iscase3(s, n)) return true;
        return false;
    }
};