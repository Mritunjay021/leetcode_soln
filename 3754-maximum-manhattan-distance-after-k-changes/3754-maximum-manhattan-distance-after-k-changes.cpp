class Solution {
public:
    int maxDistance(string st, int k) 
    {
        int n=0,s=0,e=0,w=0,mx=INT_MIN;

        for(int i=0;i<st.length();i++)
        {
            if(st[i]=='N')n++;
            if(st[i]=='S')s++;
            if(st[i]=='E')e++;
            if(st[i]=='W')w++;

            int md=abs(n-s)+abs(e-w);

            int dis=md+min(2*k,i+1-md);

            mx=max(mx,dis);
        }
        return mx;
    }
};