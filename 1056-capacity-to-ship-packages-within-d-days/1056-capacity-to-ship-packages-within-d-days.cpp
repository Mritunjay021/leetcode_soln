class Solution {
public:

    int func(vector<int>& wt,int re)
    {
        int d=1,s=0;
        for(int i=0;i<wt.size();i++)
        {
            if(s+wt[i]>re)
            {
                d++;
                s=wt[i];
            }
            else
            s+=wt[i];
        }
        return d;
    }

    int shipWithinDays(vector<int>& wt, int days) 
    {
        int l=wt[0],u=0;
        for(int i=0;i<wt.size();i++)
        {
            l=max(l,wt[i]);
            u+=wt[i];
        }
        while(l<=u)
        {
            int m=(l+u)/2;

            int re=func(wt,m);
            if(re<=days)
            {
                u=m-1;
            }
            else
            l=m+1;
        }   
        return l;
    }
};