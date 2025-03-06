class Solution {
public:
    long long coloredCells(int n) 
    {
        if(n==1)
        return 1;

        long long a=n;
        return ((a*a)+((a-1)*(a-1)));    
    }
};