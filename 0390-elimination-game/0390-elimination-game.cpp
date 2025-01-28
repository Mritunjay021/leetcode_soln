class Solution {
public:
    int func(int n,bool re)
    {
        if(n==1)
        return 1;

        if(re)
        return 2*func(n/2,0);
        else
        {
            if(n%2==0)
            return 2*func(n/2,1)-1;
            else
            return 2*func(n/2,1);
        }
    }

    int lastRemaining(int n) 
    {
        return func(n,1);
    }
};