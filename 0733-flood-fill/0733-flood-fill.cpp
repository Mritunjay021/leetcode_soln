class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m=image.size();
        int n=image[0].size();
        
        int clr=image[sr][sc];
        
        if(clr==color)
        return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});  

        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};

        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            image[x][y]=color;

            for(int i=0;i<4;i++)
            {
                int nx=x+dr[i];
                int ny=y+dc[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n 
                && image[nx][ny]==clr)
                {
                    q.push({nx,ny});
                }
            }
        } 

        return image;
    }
};