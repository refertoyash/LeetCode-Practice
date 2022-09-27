
#define all(v) v.begin(), v.end()

class Solution
{
public:
  void assignL(int l, int r, string &s)
  {
    for (int i = l; i <= r; i++)
      s[i] = 'L';
  }

  void assignR(int l, int r, string &s)
  {
    for (int i = l; i <= r; i++)
      s[i] = 'R';
  }
  string pushDominoes(string s)
  {
    s.push_back('R');
    reverse(all(s));
    s.push_back('L');
    reverse(all(s));

    int n = s.size();
    vector<pair<int, int>> setL;
    vector<pair<int, int>> setR;

    unordered_map<char, int> last;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '.')
        continue;
      else
      {
        if (last.empty())
        {
          last[s[i]] = i;
        }
        else
        {
          char before = last.begin()->first;
          int idxl = last.begin()->second;
          char curr = s[i];
          if (curr == 'L')
          {
            last.clear();
            last[s[i]] = i;
            if (before == 'L')
              setL.push_back({idxl,
                              i});
            else
            {
              int length = i - idxl - 1;
              int mid = length / 2;
              setR.push_back({idxl,
                              idxl + mid});
              setL.push_back({i - mid,
                              i});
            }
          }
          else if (curr == 'R')
          {
            last.clear();
            last[s[i]] = i;
            if (before == 'R')
              setR.push_back({idxl,
                              i});
            else
            {
              continue;
            }
          }
        }
      }
    }

    for (auto &v : setL)
    {
      assignL(v.first, v.second, s);
    }
    for (auto &v : setR)
    {
      assignR(v.first, v.second, s);
    }

    // moving ahead
    s.pop_back();
    reverse(all(s));
    s.pop_back();
    reverse(all(s));
    return s;
  }
};