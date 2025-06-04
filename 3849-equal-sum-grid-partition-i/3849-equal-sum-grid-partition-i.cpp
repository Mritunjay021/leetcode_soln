class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        typedef long long ll;

        int m=grid.size();
        int n=grid[0].size();

        vector<ll> h(m,0);
        vector<ll> v(n,0);

        for(int i=0;i<m;i++)
        {
            ll sm=0;
            for(int j=0;j<n;j++)
            {
                sm+=grid[i][j];
            }
            h[i]=sm;
        }

        for(int i=0;i<n;i++)
        {
            ll sm=0;
            for(int j=0;j<m;j++)
            {
                sm+=grid[j][i];
            }
            v[i]=sm;
        }

        ll hsum=0,vsum=0;

        for(int i=0;i<m;i++)
        hsum+=h[i];

        for(int i=0;i<n;i++)
        vsum+=v[i];

        ll hcp=0,vcp=0;

        for(int i=0;i<m-1;i++)
        {
            hcp+=h[i];
            if(hsum==hcp*2)
            return 1;
        }

        for(int i=0;i<n-1;i++)
        {
            vcp+=v[i];
            if(vsum==vcp*2)
            return 1;
        }
          
        return 0;
    }
};