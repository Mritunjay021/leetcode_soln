class Solution {
public:

    void dfs(vector<int>& vis,vector<vector<int>>& v,int i)
    {
        vis[i]=1;
        for(int j=0;j<v[i].size();j++)
        {
            if(!vis[v[i][j]])
            dfs(vis,v,v[i][j]);
        }
    }

    int numSimilarGroups(vector<string>& str) 
    {
        int n=str.size();
        vector<vector<int>> v(n);

        for(int i=0;i<str.size();i++)
        {
            string a=str[i];
            for(int j=i+1;j<str.size();j++)
            {
                int c=0;
                string b=str[j];
                for(int k=0;k<b.length();k++)
                {
                    if(b[k]!=a[k])
                    c++;
                }

                if(c<=2)
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }

                c=0;
            }
        }

        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(!vis[i])
            {
                dfs(vis,v,i);
                ans++;
            }
        }

        return ans;
    }
};