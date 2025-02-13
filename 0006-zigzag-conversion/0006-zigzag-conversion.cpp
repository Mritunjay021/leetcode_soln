class Solution {
public:
    string convert(string s, int n) 
    {
        int l=s.length();
        
        if(l<=2 || n<=1)
        return s;

        int it=2*(n-1);
        
        string t="";

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<l;j+=it)
            {
                t+=s[j];

                if(i>0 && i<n-1)
                {
                    int si=j+it-2*i;
                    if(si<l)
                    t+=s[si];
                }
            }
        }
        return t;
    }
};