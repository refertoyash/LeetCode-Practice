class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {
            int i = 0, j  = 0;
            int n = pushed.size();
            stack<int> st;
            vector<int> pop;
            while(i<n && j<n){
                st.push(pushed[i]); i++;
                while(j<n && !st.empty() && st.top()==popped[j]){
                    pop.push_back(st.top());
                    st.pop();
                    j++;
                }
            }
            while(!st.empty()){
                pop.push_back(st.top());
                st.pop();
            }
            return pop==popped;
        }
};