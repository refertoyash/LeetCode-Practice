class Solution
{
    public:

        vector<string> commonChars(vector<string> &words)
        {
            vector<string> vs;	//vector of string to store all the common charcters
            map<char, int> common;	// This will store frequency of common chracters
           	//Ex: In given test case['e', 'l', 'l'] . This will store { 	e = 1, l = 2}

            /*
            LOGIC:  For every character from[a,z]
                I'll check ki first string me 'a' kitni baar aya
                I'll check ki second string me 'a' kitni baar aya
                I'll check ki third string me 'a' kitni baar aya ....... so on

                Getting Number of times 'a' common in all string: minimum of count of 'a' among all                     strings. (Storing this data in my map "common")

                Then 

                I'll check ki first string me 'b' kitni baar aya
                I'll check ki second string me 'b' kitni baar aya
                I'll check ki third string me 'b' kitni baar aya ....... so on

                Getting Number of times 'b' common in all string: minimum of count of 'b' among all                     strings. (Storing this data in my map "common")

                ...similarly till z 
            */

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                int mini = 1e8;
                for (int j = 0; j < words.size(); j++)
                {
                    map<char, int> this_word;
                    for (auto &alpha: words[j]) this_word[alpha]++;
                    mini = min(mini, this_word[ch]);
                }
                if (mini > 0) common[ch] = mini;
            }

            /*Finally since we have to return answer in a vector of string we are converting obtained               data in desired format*/

            for (auto &v: common)
            {
                while (v.second--)
                {
                    string temp;
                    temp.push_back(v.first);
                    vs.push_back(temp);
                }
            }

            return vs;
        }
};