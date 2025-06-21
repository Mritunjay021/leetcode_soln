class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if(n==1)
        return {0};

        vector<int> id(n,0);
        vector<vector<int>> adj(n);

        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            id[it[0]]++;
            id[it[1]]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(id[i]==1)
            q.push(i);
        }

        vector<int> re;

        while(!q.empty())
        {
            int sz=q.size();
            re.clear();

            for(int i=0;i<sz;i++)
            {
                int n=q.front();
                q.pop();
                re.push_back(n);

                for(auto it:adj[n])
                {
                    id[it]--;
                    if(id[it]==1)
                    q.push(it);
                }
            }
        }

        return re;

    }
};