class Solution {
public:
    int mySqrt(int x) 
    {
        if(x<=1)
        return x;

        int l=0,h=x/2;

        while(l<=h)
        {
            long long m = (l + h) / 2;
            
            if(m * m == x) 
            return m;

            if(m*m < x)
            l=m+1;
            else
            h=m-1;
        }    

        return h;
    }
};