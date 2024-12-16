class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        vector<int> w(100001,0);
        vector<int> l(100001,0);
        vector<vector<int>> re(2);

        for(int i=0;i<matches.size();i++)
        {
            w[matches[i][0]]++;
            l[matches[i][1]]++;
        }  

        for(int i=1;i<100001;i++)
        {
            if(w[i]>0 && l[i]==0)
            re[0].push_back(i);
        }

        for(int i=1;i<100001;i++)
        {
            if(l[i]==1)
            re[1].push_back(i);
        }
        return re;
    }
};