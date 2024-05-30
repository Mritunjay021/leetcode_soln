class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length()!=t.length())
        return false;
        if(s==t)
        return true;
        int a1[26]={0},a2[26]={0};
        for(int i=0;i<s.length();i++)
        {
            a1[s[i]-97]+=1;
            a2[t[i]-97]+=1;
        }
        for(int i=0;i<26;i++)
        {
            if(a1[i]!=a2[i])
            return false;
        }
        return true;
    }
};