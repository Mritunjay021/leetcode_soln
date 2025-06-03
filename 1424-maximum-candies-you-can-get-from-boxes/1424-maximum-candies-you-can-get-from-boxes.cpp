class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        int n=status.size();
        queue<int> q;
        vector<int> hkey(n,0);
        vector<int> hbox(n,0);
        vector<int> vis(n,0);
        int candy=0;

        for(int i=0;i<initialBoxes.size();i++)
        {
            hbox[initialBoxes[i]]=1;
            if(status[initialBoxes[i]])
            q.push(initialBoxes[i]);
        }  

        while(!q.empty())
        {
            int cb=q.front();
            q.pop();

            if (vis[cb]) continue;

            candy+=candies[cb];
            vis[cb]=1;

            for(int k:keys[cb])
            hkey[k]=1;

            for(auto it:containedBoxes[cb])
            {
                hbox[it]=1;
                if(hkey[it] || status[it])
                q.push(it);
            }

            for(int i=0;i<n;i++)
            {
                if(!vis[i] && hbox[i] && hkey[i])
                q.push(i);
            }
            
        }
        return candy;
    }
};