class Solution {
public:

    int func(vector<int>& v,int m)
    {
        int cp=0;
        for(int i=0;i<v.size()-1;i++)
        {
            if(abs(v[i]-v[i+1])<=m)
            {
                i++;
                cp++;
            }
        }
        return cp;
    }

    int minimizeMax(vector<int>& v, int p) 
    {
        int n=v.size();
        
        sort(v.begin(),v.end());

        int l=0,h=v[n-1]-v[0];

        while(l<=h)
        {
            int m=(l+h)/2;
            int re=func(v,m);
            if(re<p)
            l=m+1;
            else
            h=m-1;
        }
        return l;
    }
};