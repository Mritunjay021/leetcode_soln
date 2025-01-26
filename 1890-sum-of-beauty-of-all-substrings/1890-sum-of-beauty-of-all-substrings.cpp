class Solution {
public:
    int beautySum(string s) 
    {
        int n=s.length(),sm=0;
        for(int i=0;i<n;i++)
        {
            int ar[26]={0};
            for(int j=i;j<n;j++)
            {
                ar[s[j]-'a']++;
                int mx=INT_MIN,mn=INT_MAX;
                for(int l=0;l<26;l++)
                {
                    if(ar[l]>0)
                    {
                        mx=max(ar[l],mx);
                        mn=min(ar[l],mn);
                    }
                }
                sm+=(mx-mn);
            }
        }
        return sm;
    }
};