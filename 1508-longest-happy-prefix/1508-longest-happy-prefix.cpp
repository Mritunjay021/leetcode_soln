class Solution {
public:
    string longestPrefix(string s) 
    {
        int n=s.length();
        vector<int> lps(n,0);
        int l=0,i=1;

        while(i<n)
        {
            if(s[i]!=s[l])
            {
                if(l==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    l=lps[l-1];
                }
            }
            else if(s[i]==s[l])
            {
                l++;
                lps[i]=l;
                i++;
            }
        } 
        int mx=lps[n-1];
        return s.substr(0,mx);   
    }
};