class Solution {
public:
    int maximumWealth(vector<vector<int>>& m) 
    {
        int s=0,mx=0;
        for(int i=0;i<m.size();i++)
        {
            for(int j=0;j<m[0].size();j++)
            {
                s+=m[i][j];
            }
            mx=max(mx,s);
            s=0;
        } 
        return mx;   
    }
};