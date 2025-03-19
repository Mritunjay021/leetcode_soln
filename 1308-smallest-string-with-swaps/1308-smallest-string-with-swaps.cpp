class Solution {
public:

    void dfs(vector<bool>& vis,int i,vector<list<int>>& adj,
            string& s,vector<char>& ch,vector<int>& id)
    {
        ch.push_back(s[i]);
        id.push_back(i);
        
        vis[i]=1;

        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(vis,it,adj,s,ch,id);
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int v=s.length();
        vector<list<int>> adj(v);

        for (int i = 0; i < pairs.size(); i++) 
        {
            adj[pairs[i][0]].push_back(pairs[i][1]);
            adj[pairs[i][1]].push_back(pairs[i][0]);
        }

        vector<bool> vis(v,0);

        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                vector<char> ch;
                vector<int> id;
                
                dfs(vis,i,adj,s,ch,id);

                sort(ch.begin(),ch.end());
                sort(id.begin(),id.end());

                for(int j=0;j<ch.size();j++)
                s[id[j]]=ch[j];
            }
        }

        return s;
    }
};