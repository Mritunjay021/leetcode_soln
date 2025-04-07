class Solution {
public:

    vector<pair<int,int>> v;

    void dfs(vector<vector<int>>& grid,int r,int c,int oc,int clr)
    {
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!=oc)
        return;

        grid[r][c]=-clr;

        dfs(grid,r-1,c,oc,clr);
        dfs(grid,r+1,c,oc,clr);
        dfs(grid,r,c-1,oc,clr);
        dfs(grid,r,c+1,oc,clr);

        if(r>0 && c>0 && r<grid.size()-1 && c<grid[0].size()-1 &&
            grid[r-1][c]==-clr && grid[r+1][c]==-clr && grid[r][c+1]==-clr && grid[r][c-1]==-clr)
        v.push_back({r,c});
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r, int c, int clr) 
    {
        int m=grid.size();
        int n=grid[0].size();

        int oc=grid[r][c];

        if(oc==clr)
        return grid;

        dfs(grid,r,c,oc,clr);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == -clr)
                grid[i][j]=clr;
            }
        }

        for(auto it:v)
        {
            int r1=it.first;
            int c1=it.second;

            grid[r1][c1]=oc;
        }

        return grid;
    }
};