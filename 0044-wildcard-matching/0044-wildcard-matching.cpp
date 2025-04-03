class Solution {
public:

    bool func(string s,string p,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=s.length() && j>=p.length())
        return true;

        if(j>=p.length() && i<s.length())
        return false;

        if (i >= s.length()) {
            for (; j < p.length(); j++)
                if (p[j] != '*') return false;
            return true;
        }

        // if(j>=p.length() && i<s.length())
        // return false;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s[i]==p[j] || p[j]=='?')
        return dp[i][j]=func(s,p,i+1,j+1,dp);
        else if(p[j]=='*')
return dp[i][j]=func(s,p,i,j+1,dp) || func(s,p,i+1,j,dp);
        else
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) 
    {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(s,p,0,0,dp);
    }
};