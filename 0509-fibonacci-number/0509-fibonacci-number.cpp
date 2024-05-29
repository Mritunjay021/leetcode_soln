class Solution {
public:
    long long sum(long long a,long long b,long long n,long long i)
    {
        if(i==n)
        return a+b;
        if(a+b>=INT_MAX)
        return INT_MAX;
        return sum(b,a+b,n,i+1);
        
    }

    long long fib(int n) 
    {
        if(n==0)
        return 0;
        else if(n==1||n==2)
        return 1;
        else
        return sum(0,1,n,2);
    }
};