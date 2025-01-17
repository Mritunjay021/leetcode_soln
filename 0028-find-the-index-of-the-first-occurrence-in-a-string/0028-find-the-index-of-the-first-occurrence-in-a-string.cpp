class Solution {
public:
    int strStr(string s, string t) 
    {
        int j=0,i=0,l=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==t[l])
            l++;
            else
            {
                i=i-l;
                l=0;
            }

            if(l==t.length())
            {
                return i-l+1;
            }
        }
        return -1;
    }
};