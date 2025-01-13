class Solution {
public:

    long long func(vector<int>& piles,int m)
    {
        long long s=0;
        for(int i=0;i<piles.size();i++)
        {
            s+=ceil((double)(piles[i]) / (double)(m));;
        }
        return s;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l=1,u=INT_MIN,ans;
        for(int i=0;i<piles.size();i++)
        u=max(u,piles[i]);

        while(l<=u)
        {
            int m=(l+u)/2;
            long long re=func(piles,m);

            if(re<=h)
            {
                ans=m;
                u=m-1;
            }
            else
            l=m+1;

        }
        return ans;

    }
};