class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors,int k) 
    {
        int n=colors.size();
        if(n<k) return 0;
        int re=0;
        int l=0,r=1;
        while(l<n)
        {
            if(colors[r%n]!=colors[(r-1)%n] && r<n+k-1)
            r++;
            else
            {
                l=r;
                r++;
            }
            if(r-l==k)
            {
                re++;
                l++;
            }
        }
        return re;
    }
};