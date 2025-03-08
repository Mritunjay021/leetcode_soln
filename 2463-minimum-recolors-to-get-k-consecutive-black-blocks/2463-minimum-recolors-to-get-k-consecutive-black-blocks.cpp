class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int l=0,r=0,w=0,mn=INT_MAX;

        while(r<blocks.size())
        {
            if(r-l+1==k)
            {
                for(int i=l;i<=r;i++)
                {
                    if(blocks[i]=='W')
                    w++;
                }
                mn=min(mn,w);
                l++;
                w=0;
            }
            r++;
        }    
        return mn;
    }
};