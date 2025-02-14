class Solution {
public:
    int mod=1e9+7;

    long long func(long long x,long long n)
    {
        long long re=1;

        while(n>0)
        {
            if(n&1)
            {
                re=(re*x)%mod;
            }

            x=(x*x)%mod;
            n=n>>1;
        }
        
        return re;
    }

    int monkeyMove(int n) 
    {
        return int((func(2,n)-2+mod)%mod);
    }
};