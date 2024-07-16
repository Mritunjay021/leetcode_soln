class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
        return -1;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0]=true;
        pq.push({1,{0,0}});
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
     
        while(!pq.empty())
        {
            int d=pq.top().first;
            pair<int,int> node=pq.top().second;
            pq.pop();
            int r = node.first;
            int c = node.second;
            if(r == n-1 && c == n-1)
                return d;
            for(int i=0;i<8;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && !vis[nr][nc])
                {
                    pq.push({d+1,{nr,nc}});
                    vis[nr][nc]=true;
                }
            }
        }
        return -1;
    }
};