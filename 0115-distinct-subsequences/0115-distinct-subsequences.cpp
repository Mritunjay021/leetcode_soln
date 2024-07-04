class Solution {
public:

    int f(string s,string t,int i,int j,vector<vector<int>>& dp)
    {
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s[i]==t[j])
        return dp[i][j]=f(s,t,i-1,j-1,dp)+f(s,t,i-1,j,dp);

        return dp[i][j]=f(s,t,i-1,j,dp);
    }

    int numDistinct(string s, string t) 
    {
        int l1=s.size();
        int l2=t.size();
        vector<vector<double>> dp(l1+1,vector<double>(l2+1,0));
        // return f(s,t,l1-1,l2-1,dp);
        for(int i=0;i<=l1;i++)
        dp[i][0]=1;

        for(int i=1;i<=l2;i++)
        dp[0][i]=0;
        
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[l1][l2];
    }
};