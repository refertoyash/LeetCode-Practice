class Solution
{
    public:
        int maxArea(vector<int> &ht)
        {
            int mxarea = INT_MIN;
            int l = 0, r = ht.size() - 1;
            while (r > l)
            {
                mxarea = max(mxarea, (r - l) *min(ht[l], ht[r]));
                if (min(ht[l], ht[r]) == ht[l]) l++;
                else r--;
            }
            return mxarea;
        }
};