class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //applying bfs 
        set<string> ls;
        for(int i = 0; i<wordList.size(); i++){
            ls.insert(wordList[i]);
        }
        
        queue<string> q;
        map<string,bool> vis;
        q.push(beginWord);
        vis[beginWord] = true;
        
        int level = 1;
        while(!q.empty()){
            
            int k = q.size();

            //neighbors: all possibilities of next state which is also present in ls
            while(k--){
                string curr = q.front();
                q.pop();
                for(int i = 0; i<curr.size(); i++){
                    string temp = curr;
                    for(char j = 'a'; j<='z'; j++){
                        temp[i] = j;
                        // cout<<temp<<"\n";
                        if(ls.find(temp)!=ls.end()){
                            //proper neighbour
                            // cout<<temp<<"--"<<level<<"\n";
                            if(temp==endWord) return level+1;
                            if(vis[temp]) continue;
                            q.push(temp);
                            vis[temp] = true;
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};