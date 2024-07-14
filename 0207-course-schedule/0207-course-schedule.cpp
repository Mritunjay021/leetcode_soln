class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[V];
        for(auto it:prerequisites)
        adj[it[0]].push_back(it[1]);

        vector<int> ed(V,0);
	   for(int i=0;i<V;i++)
	   {
	       for(auto it:adj[i])
	        ed[it]++;
	   }
	   queue<int> q;
	   for(int i=0;i<V;i++)
	   {
	       if(ed[i]==0)
	       q.push(i);
	   }
	   vector<int> ans;
	   while(!q.empty())
	   {
	       int node=q.front();
	       q.pop();
	       ans.push_back(node);
	       for(auto it:adj[node])
	       {
	           ed[it]--;
	           if(ed[it]==0)
	           q.push(it);
	       }
	   }
        if(ans.size()==V)
        return true;
        else
        return false;
    }
};