class Solution {
public:
    int countDigitOne(int n) 
    {
        if(n==0)
        return 0;

        if(n<=9)
        return 1;

        int len=log10(n)+1;

        int base=pow(10,len-1);

        int firstno=n/base;

        int rem=n%base;

        int numof1=0;
        if(firstno==1)
        {
            numof1=n-base+1;
        }
        else
        numof1=base;

        return countDigitOne(base-1)*firstno+numof1+countDigitOne(rem);
    }
};