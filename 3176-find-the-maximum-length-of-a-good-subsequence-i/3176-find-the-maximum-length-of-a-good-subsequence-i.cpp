class Solution {
public:

    int dp[501][502][26];

    int func(vector<int>& num,int k,int i,int j)
    {
        if(i>=num.size())
        return 0;

        if(dp[i][j+1][k]!=-1)
        return dp[i][j+1][k];

        int p=0;
        if(j==-1 || num[i]==num[j])
        p=1+func(num,k,i+1,i);
        else if(k>0)
        p=1+func(num,k-1,i+1,i);

        int np=func(num,k,i+1,j);

        return dp[i][j+1][k]=max(p,np);
    }

    int maximumLength(vector<int>& num, int k) 
    {
        int n=num.size();
        memset(dp,-1,sizeof(dp));
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+2, vector<int>(k+1, -1)));
        return func(num,k,0,-1);
    }
};