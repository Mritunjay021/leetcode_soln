class Solution {
public:
    long long distributeCandies(int n, int limit) 
    {
        long long w=0;

        for(int c1=0;c1<=min(n,limit);c1++)
        {
            int rem=n-c1;

            if(rem>2*limit)
            continue;

            w+=min(limit,rem)-max(rem-limit,0)+1;
        }    

        return w;
    }
};