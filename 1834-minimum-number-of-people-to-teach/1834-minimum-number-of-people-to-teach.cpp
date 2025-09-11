class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& frnds) 
    {
        unordered_set<int> sad;

        for(auto frnd:frnds)
        {
            int u=frnd[0]-1;
            int v=frnd[1]-1;
            
            bool cantalk=0;

            for(auto lu:lang[u])
            {
                for(auto lv:lang[v])
                {
                    if(lu==lv)
                    {
                        cantalk=1;
                        break;
                    }
                }
                
                if(cantalk)
                break;
            }

            if(!cantalk)
            {
                sad.insert(u);
                sad.insert(v);
            }
        }   

        vector<int> langs(n+1,0);
        int ans=0;

        for(auto it:sad)
        {
            for(int lng:lang[it])
            {
                langs[lng]++;
                ans=max(ans,langs[lng]);
            }
        }

        return sad.size()-ans;
    }
};