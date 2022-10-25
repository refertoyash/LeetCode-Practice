class Solution
{
    //NOW IT'S DONE \U0001f338
    public:
        bool isvalid(string s, string ns)
        {
           	// s and ns me kuch bhi common na ho
            set<char> sns;
            for (int i = 0; i < ns.size(); i++) sns.insert(ns[i]);
            if (sns.size() != ns.size()) return false;
            set<char> ss;
            for (int i = 0; i < s.size(); i++) ss.insert(s[i]);
            for (auto &v: sns)
            {
                if (ss.find(v) != ss.end()) return false;
            }
            return true;
        }

    int max_till_this_id(vector<string> &arr, int id, string s)
    {
        if (id < 0) return 0;
        int picked = 0, nonpicked = 0;
        if (id == 0)
        {
            if (isvalid(s, arr[0])) picked = s.length() + arr[0].length();
            nonpicked = s.length();
            return max(picked, nonpicked);
        }
        if (isvalid(s, arr[id]))
        {
            picked = max_till_this_id(arr, id - 1, s + arr[id]);
        }
        nonpicked = max_till_this_id(arr, id - 1, s);
        return max(picked, nonpicked);
    }

    int maxLength(vector<string> &A)
    {
        return max_till_this_id(A, A.size() - 1, "");
    }
};