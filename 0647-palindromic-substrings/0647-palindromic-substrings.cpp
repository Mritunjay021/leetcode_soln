class Solution {
public:

    int func(string& s,int l,int r,vector<vector<int>>& dp)
    {
        if(l>=r)
        return 1;

        if(dp[l][r]!=-1)
        return dp[l][r];

        if(s[l]==s[r])
        dp[l][r]= func(s,l+1,r-1,dp);
        else 
        dp[l][r]= 0;
        return dp[l][r];
    }

    int countSubstrings(string s) 
    {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int re=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(func(s,i,j,dp))
                re++;
            }
        }
        return re;
    }
};