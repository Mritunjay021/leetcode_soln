class Solution {
public:

    void func(vector<int>& mat,vector<vector<int>>& grid)
    {
        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat.push_back(grid[i][j]);
            }
        }
    }

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        vector<int> mat;

        func(mat,grid);

        int k=0,n=mat.size();

        for(int i=0;i<n;i++)
        {
            k^=mat[i];
            k^=i+1;
        }

        int setbit=k&~(k-1);

        int x=0,y=0;

        for(int i=0;i<n;i++)
        {
            if(setbit&mat[i])
            x^=mat[i];
            else
            y^=mat[i];

            if(setbit&(i+1))
            x^=i+1;
            else
            y^=i+1;
        }

        for(int i=0;i<n;i++)
        {
            if(mat[i]==x)
            return {x,y};
        }
        return {y,x};
    }
};