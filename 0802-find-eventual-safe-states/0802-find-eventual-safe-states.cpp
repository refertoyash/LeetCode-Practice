class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //topo sort (cycle mili to ignore else ) topo
        map<int,vector<int>> adj;
        for(int i = 0; i< graph.size(); i++){
            for(int j = 0; j<graph[i].size(); j++) adj[graph[i][j]].push_back(i);
        }
        int n = graph.size();
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
        sort(topo.begin(),topo.end());
        return topo;
    }
};