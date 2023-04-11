class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> adj;
        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        
        queue<int> q;
        vector<int> topo;
        vector<int> indeg(n,0);
        for(auto &p: adj){
            for(int i = 0 ; i<p.second.size(); i++) indeg[p.second[i]]++;
        }
        
        for(int i = 0; i<indeg.size(); i++)
           if(indeg[i]==0) q.push(i);
        
        while(!q.empty()){
            int curr = q.front();
            topo.push_back(curr);
            q.pop();
            
            for(auto &dost:adj[curr]){
                indeg[dost]--;
                if(indeg[dost]==0) q.push(dost);
            }
        }
        if(topo.size()==n) return topo;
        return {};
        
    }
};