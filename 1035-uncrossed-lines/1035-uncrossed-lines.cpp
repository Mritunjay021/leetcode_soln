class Solution {
public:

    int func(vector<int>& n1,vector<int>& n2,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=n1.size() || j>=n2.size())
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(n1[i]==n2[j])
        {
            int p=1+func(n1,n2,i+1,j+1,dp);

            int np=func(n1,n2,i,j+1,dp);

            dp[i][j]=max(p,np);

            return dp[i][j];
        }

        dp[i][j]=max(func(n1,n2,i,j+1,dp),max(func(n1,n2,i+1,j+1,dp),func(n1,n2,i+1,j,dp)));

        return dp[i][j];
    }

    int maxUncrossedLines(vector<int>& num1, vector<int>& num2) 
    {
        vector<vector<int>> dp(num1.size()+1,vector<int>(num2.size()+1,-1));

        return func(num1,num2,0,0,dp);
    }
};