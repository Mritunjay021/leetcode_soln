class Solution {
public:
    int maxScore(vector<int>& ar, int k) 
    {
        int ls=0,rs=0,mx=0;
        for(int i=0;i<k;i++)
        {
            ls+=ar[i];
        }
        mx=ls;
        int ri=ar.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            ls-=ar[i];
            rs+=ar[ri];
            ri--;
            mx=max(mx,ls+rs);
        }
        return mx;
    }
};