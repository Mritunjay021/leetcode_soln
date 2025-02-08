class Solution {
public:
    string getHint(string s, string g) 
    {
        int a=0,b=0;
        int m1[10]={0};
        int m2[10]={0};

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==g[i])
            a++;
            else
            {
                m1[s[i]-'0']++;
                m2[g[i]-'0']++;
            }
        }  

        for(int i=0;i<10;i++)
        {
            if(m1[i]>=1 && m2[i]>=1)
            b+=min(m1[i],m2[i]);
        } 
        string st=""+to_string(a)+"A"+to_string(b)+"B";
        return st;
    }
};