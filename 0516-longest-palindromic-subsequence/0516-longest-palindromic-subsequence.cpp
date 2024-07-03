class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        string t=s;
        reverse(t.begin(),t.end());
        int i=s.length(),j=s.length();
        vector<vector<int>> dp(i+1,vector<int>(j+1,0));
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
    }
};