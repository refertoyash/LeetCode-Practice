class Solution
{
    public:
        string breakPalindrome(string palindrome)
        {
            int n = palindrome.size();
            int st = 0, end = n - 1;

            while (st < end)
            {
                if (st == end)
                {
                    st++;
                    end--;
                    continue;
                }
                if (palindrome[st] != 'a')
                {
                    palindrome[st] = 'a';
                    return palindrome;
                }
                st++, end--;
            }
            if (n == 1) return "";
            palindrome[n - 1] = 'b';
            return palindrome;
        }
};