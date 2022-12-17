
class Solution
{   
    public:
    vector<string> ans;
        void rec(int op, int cl, string &s, int n)
        {
            if (op > n || cl > n) return;
            if (cl > op) return;
            if (op == n && cl == n)
            {
                ans.push_back(s);
                return;
            }

            s.push_back('(');
            rec(op + 1, cl, s, n);
            s.pop_back();
            s.push_back(')');
            rec(op, cl + 1, s, n);
            s.pop_back();
            return;
        }
    vector<string> generateParenthesis(int n)
    {
        string s = "";
        rec(0, 0, s, n);
        return ans;
    }
};