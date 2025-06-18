class Solution {
public:

    bool dfs(int n,int c,vector<int>& col,vector<vector<int>>& graph)
    {
        col[n]=c;

        for(auto it:graph[n])
        {
            if(col[it]==-1)
            {
                if(!dfs(it,!c,col,graph))
                return false;
            }
            else if(col[it] == c)
            return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> col(n,-1);

        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!dfs(i,0,col,graph))
                return false;
            }
        }

        return true;
    }
};