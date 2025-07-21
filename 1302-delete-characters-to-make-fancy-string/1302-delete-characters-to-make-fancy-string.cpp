class Solution {
public:
    string makeFancyString(string s) 
    {
        string re;
        int n=s.length();

        if(n<3)
        return s;

        for(int i=1;i<n-1;i++)
        {
            if(s[i]==s[i-1] && s[i]==s[i+1])
            continue;

            re+=s[i];
        }    

        return (s[0]+re+s[n-1]);
    }
};