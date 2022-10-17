class Solution
{
    public:
        bool checkIfPangram(string sentence)
        {
            set<char> st;
            for (char c = 'a'; c <= 'z'; c++) st.insert(c);
            for (int i = 0; i < sentence.size(); i++)
            {
                if (st.find(sentence[i]) != st.end()) st.erase(sentence[i]);
            }
            return st.empty();
        }
};