class Solution {
public:

    int f(int i,int j,string& s,string& t,vector<vector<int>>& dp)
    {
        if(i<0 || j<0)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s[i]==t[j])
        return dp[i][j]=1+f(i-1,j-1,s,t,dp);

        return dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }

    int longestCommonSubsequence(string s, string t) 
    {
        int i=s.size();
        int j=t.size(); 
        vector<vector<int>> dp(i+1,vector<int>(j+1,0));
        // for(int a=0;a<=i;a++)
        // dp[a][0]=0;
        // for(int a=0;a<=j;a++)
        // dp[0][a]=0;
        for(int a=1;a<=i;a++)
        {
            for(int b=1;b<=j;b++)
            {
                if(s[a-1]==t[b-1])
                dp[a][b]=1+dp[a-1][b-1];
                else
                dp[a][b]=max(dp[a-1][b],dp[a][b-1]);
            }
        }
        return dp[i][j];
        //return f(i-1,j-1,s,t,dp);
    }
};