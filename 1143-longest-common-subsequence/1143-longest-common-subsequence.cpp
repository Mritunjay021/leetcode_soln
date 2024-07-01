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
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return f(i-1,j-1,s,t,dp);
    }
};