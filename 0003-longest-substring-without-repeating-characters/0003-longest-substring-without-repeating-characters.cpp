class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int f=0,mx=0;
        char c;string sub="";
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                c=s[j];
                auto it=s.substr(i,j-i).find(c);
                if(j-i==0 || it==sub.npos)
                {
                    f++;
                }
                else 
                break;
            }
            mx=max(f,mx);
            f=0;
        }
        return mx;
    }
};