class Solution
{
    public:
        bool isposs(int k, string s)
        {
           	//kya k length ki aisi substring present hai jisme sare elements unique ho
            if(k==0) return true;
            int i = 0, j = 0;
            map<char, int> mp;
            while (j < s.size())
            {
                mp[s[j]]++;
                if (j - i + 1 < k) j++;
                else if (j - i + 1 == k)
                {
                    if ((int)mp.size() == k) return true;
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                    j++;
                }
            }
            return false;
        }

    int lengthOfLongestSubstring(string s)
    {

       	/// T T T F F F F F (Finding last true)
        int st = 0, end = s.size();
        while (end - st > 1)
        {
            int mid = (st + end) / 2;
            if (isposs(mid, s)) st = mid;
            else end = mid - 1;
        }
        if (isposs(end, s)) return end;
        return st;
    }
};