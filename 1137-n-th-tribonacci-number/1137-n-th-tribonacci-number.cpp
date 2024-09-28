class Solution {
public:

    int func(int n,int a,int b,int c,int i)
    {
        if(i==n-1)
        return c;
        return func(n,b,c,a+b+c,i+1);
        
    }


    int tribonacci(int n) 
    {
        // int s=0; 
        // if(n==0)
        // return 0;
        // if(n==1)
        // return 1;
        // return func(n,0,1,1,1);

        if(n < 3) {
            return n > 0 ? 1 : 0;
        }

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;

        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
        
    } 
    
};