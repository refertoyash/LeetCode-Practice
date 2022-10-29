class Solution
{
    public:
        int earliestFullBloom(vector<int> &pt, vector<int> &gt)
        {
            int ans = 0;
            int n = pt.size();
            int mxday = -1;
            int nplantid = 0;
            vector<pair<int, int>> vp;
            for (int i = 0; i < n; i++)
            {
                vp.push_back({ gt[i],
                    pt[i] });
            }
            
            sort(vp.rbegin(), vp.rend());

            for (int i = 0; i < n; i++)
            {
                int day_here = nplantid + vp[i].first + vp[i].second;
                mxday = max(mxday, day_here);
                nplantid += vp[i].second;
            }
            return mxday;
        }
};