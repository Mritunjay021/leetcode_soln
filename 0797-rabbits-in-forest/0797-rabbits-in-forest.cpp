class Solution {
public:
    int numRabbits(vector<int>& ans) 
    {
        unordered_map<int,int> mp;
        
        for(auto it:ans)
        {
            mp[it]++;
        }  

        int re=0;

        for(auto it:mp)
        {
            if(it.first==0)
            re+=it.second;
            else
            re+=(it.first+1)*((it.second + it.first)/(it.first+1));
        }

        return re;
    }
};