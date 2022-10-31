class Solution
{
    public:
        bool isToeplitzMatrix(vector<vector < int>> &arr)
        {
            int n = arr.size();
            int m = arr[0].size();

            for (int i = 0; i < m; i++)
            {
                int ci = 0, cj = i;
                while (ci < n - 1 && cj < m - 1)
                {
                    if (arr[ci][cj] != arr[ci + 1][cj + 1]) return false;
                    ci++, cj++;
                }
            }

            for (int j = 0; j < n; j++)
            {
                int ci = j, cj = 0;
                while (ci < n - 1 && cj < m - 1)
                {
                    if (arr[ci][cj] != arr[ci + 1][cj + 1]) return false;
                    ci++, cj++;
                }
            }
            return true;
        }
};