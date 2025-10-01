class Solution {
public:
    int numWaterBottles(int tb, int c) 
    {
        int re=tb;
        int rem=0;

        while(tb+rem>=c)
        {
            int nb = (tb+rem)/c;
            rem=(tb+rem)%c;
            re+=nb;
            tb=nb;
        }    

        return re;
    }
};