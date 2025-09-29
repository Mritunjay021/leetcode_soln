class Solution {
public:

    int mod=1e9+7;

    int countHomogenous(string s) 
    {
        long long c=1,re=0;
        int i=0;
        
        while(i<s.length())
        {
            while(i+1<s.length() && s[i]==s[i+1])
            {
                c++;
                i++;
            }
            re=(re+((c*(c+1)/2)%mod))%mod;
            c=1;
            i++;
        }
        return re;
    }
};