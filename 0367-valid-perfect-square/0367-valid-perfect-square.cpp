class Solution {
public:
    bool isPerfectSquare(int n) 
    {
        if(n==1)
        return 1;

        long long l=1,u=n/2;
        while(l<=u)
        {
            long long m=(l+u)/2;
            if(m*m==n)
            return true;
            else if(m*m>n)
            u=m-1;
            else
            l=m+1;
        }
        return false;
    }
};