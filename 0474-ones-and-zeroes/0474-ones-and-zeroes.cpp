class Solution {
public:

    int func(vector<string>& str,int m,int n,int i,vector<vector<vector<int>>>& dp)
    {
        if(i>=str.size() || (m==0 && n==0))
        return 0;

        if(dp[i][m][n]!=-1)
        return dp[i][m][n];

        int np= func(str,m,n,i+1,dp);

        int z=0,o=0;
        for (char c : str[i]) {
            if (c == '0') z++;
            else o++;
        }

        int p=0;
        if(z<=m && o<=n)
        {
            p=1+func(str,m-z,n-o,i+1,dp);
        }

        return dp[i][m][n]=max(p,np);

    }

    int findMaxForm(vector<string>& str, int m, int n) 
    {
        vector<vector<vector<int>>> dp(str.size()+1,vector<vector<int>> (m+1,vector<int>(n+1,-1)));
        return func(str,m,n,0,dp);
    }
};