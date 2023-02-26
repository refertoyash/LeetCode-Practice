class Solution
{
    public:
    vector<string> ans;
    void backtrack(string digits, int id , vector<vector<char>> &vv, string temp){
          if(digits.size()==temp.size()){
              ans.push_back(temp);
              return;
          }
        
          for(int i = id; i<digits.size(); i++){
              for(int j = 0; j<vv[(digits[i]-'0')-2].size(); j++){;
                  temp.push_back(vv[(digits[i]-'0')-2][j]);
                  backtrack(digits, i+1,vv,temp);
                temp.pop_back();
              }
          }
        
    }
    
    
    vector<string> letterCombinations(string digits)
    {
        vector<vector < char>> vv;
        if(digits.size()==0) return ans;
        vv = {
		{
                'a',
                'b',
                'c' },
            {
                'd',
                'e',
                'f' },
            {
                'g',
                'h',
                'i' },
            {
                'j',
                'k',
                'l' },
            {
                'm',
                'n',
                'o' },
            {
                'p',
                'q',
                'r',
                's' },
            {
                't',
                'u',
                'v' },
            {
                'w',
                'x',
                'y',
                'z' }
        };
        backtrack(digits,0,vv,{});
        return ans;
    }
};