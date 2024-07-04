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
        vector<vector<int>> dp(l1,vector<int>(l2,-1));
        return f(s,t,l1-1,l2-1,dp);
        //for(int i=0;i<l1;i++)
    }
};