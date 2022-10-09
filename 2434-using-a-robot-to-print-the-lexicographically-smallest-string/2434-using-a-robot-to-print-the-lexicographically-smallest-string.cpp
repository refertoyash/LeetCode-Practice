class Solution
{
    public:
        string robotWithString(string s)
        {
            multiset<char> st;
            int n = s.size();
            for (int i = 0; i < n; i++) st.insert(s[i]);

            string final = "";
            string t;

            for (int i = 0; i < s.size();)
            {
                auto it = st.begin();

                while (i < n && s[i] != *it)
                {
                    t.push_back(s[i]);
                    auto x = st.find(s[i]);
                    st.erase(x);
                    i++;
                }

                if (s[i] == *it)
                {
                    auto x = st.find(s[i]);
                    st.erase(x);
                    t.push_back(s[i]);
                    i++;
                }

                while (!st.empty() && !t.empty() && t.back() <= *st.begin())
                {
                    final.push_back(t.back());
                    t.pop_back();
                }
            }

            reverse(t.begin(), t.end());
            final += t;
            return final;
        }
};