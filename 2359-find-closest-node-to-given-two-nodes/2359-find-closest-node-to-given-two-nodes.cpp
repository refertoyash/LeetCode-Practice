class Solution
{
    public:
        void trace(vector<int> &path, vector<int> &edges, int node, int dis = 0)
        {
            
       
            while (node != -1 && path[node]==-1)
            {
                path[node] = dis++;
                node = edges[node];
        
            }
            return;
        }

    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {   
        int n = edges.size();
        vector<int> path1(n,-1);
        vector<int> path2(n,-1);
        trace(path1,edges,node1);
        trace(path2,edges,node2);
        int k = INT_MAX;
        int ans = -1;
        for(int i = 0; i<n; i++){
            if(min(path1[i],path2[i])>=0 && max(path1[i],path2[i])<k){
                k = max(path1[i],path2[i]);
                ans = i;
            }
        }
        return ans;
    }
};