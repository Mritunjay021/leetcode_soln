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
    
    int countGoodNumbers(long long n) 
    {
        long long ev=(n+1)/2;
        long long ov=n/2;

        return (int)((func(5,ev)*func(4,ov))%mod);
    }

};