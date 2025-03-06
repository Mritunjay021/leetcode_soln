class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<int> v(n*n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[grid[i][j]-1]++;
            }
        } 

        int a,b;
        for(int i=0;i<n*n;i++)
        {
            if(v[i]==2)
            a=i+1;
            else if(v[i]==0)
            b=i+1;
        }

        vector<int> mp(2);
        mp[0]=a;
        mp[1]=b;

        return mp;   
    }
};