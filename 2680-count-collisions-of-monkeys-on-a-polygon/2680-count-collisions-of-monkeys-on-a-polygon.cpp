class Solution {
public:
    int mod=1e9+7;
    long func(int a,int b)
    {
        if(b==0)
        return 1;

        long t=func(a,b/2);
        long ans=t*t%mod;

        if(b%2==1)
        ans=ans*a%mod;

        return ans;
    }

    int monkeyMove(int n) 
    {
        int re=(int)func(2,n)%mod;
        return (re+mod-2)%mod;    
    }
};