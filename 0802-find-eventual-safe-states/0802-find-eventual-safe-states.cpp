class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) 
    {
        int V=adj.size();
        vector<int> adjr[V];
        vector<int> ed(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                adjr[it].push_back(i);
                ed[i]++;
            }
        }
        queue<int> q;
        vector<int> sfn;
        for(int i=0;i<V;i++)
        {
            if(ed[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            sfn.push_back(node);
            for(auto it:adjr[node])
            {
                ed[it]--;
                if(ed[it]==0)
                q.push(it);
            }
        }
        sort(sfn.begin(),sfn.end());
        return sfn;
    }
};