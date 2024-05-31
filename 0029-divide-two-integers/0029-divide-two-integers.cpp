class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        long long re=0;
        if(divisor==1)
        re = dividend;
        else if(divisor==-1)
        re =  -1*dividend;
        int d1=abs(dividend),d2=abs(divisor);
        while(d1>=d2)
        {
            re++;
            d1-=d2;
        }
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))
        re = -1*re;

        if (re>=(pow(2,31)-1))
        return (pow(2,31)-1);
        else if(re==(pow(2,-31)))
        return (pow(-2,31)+1);
        else
        return re;
    }
};