class Solution {
public:
    double knightProbability(int n, int k, int row, int col) 
    {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n,vector<double>(n,-1)));
        return solve(n,k,row,col,dp);
    }
    double solve(int n,int k, int row,int col,vector<vector<vector<double>>>& dp)
    {
        if(row>=n||col>=n||row<0||col<0)return 0;

        if(k==0)return 1;
        
        if(dp[k][row][col]!=-1)
        return dp[k][row][col];

        int dir[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
        double p=0;
        for(int i=0;i<8;i++)
        {
            p+=0.125*solve(n,k-1,row-dir[i][0],col-dir[i][1],dp);
        }
        return dp[k][row][col]=p;
    }
};