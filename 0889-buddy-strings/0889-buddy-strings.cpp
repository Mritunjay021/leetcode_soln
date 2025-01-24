class Solution {
public:
    bool buddyStrings(string s, string g) 
    {
        if(s.length()!=g.length() || s.length()<2)
        return false;
        
        map<int,int> mp;
        if(s==g)
        {
            for(int i=0;i<s.length();i++)
            {
                mp[s[i]-'a']++;
                if(mp[s[i]-'a']>=2)
                return true;
            }
            return false;
        }

        int c=0,j1=-1,j2=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=g[i])
            {
                if(j1==-1)
                j1=i;
                if(j1!=-1)
                j2=i;
                c++;
                if(c>2)
                return false;
            }
        }

        if(j1==-1 && j2==-1)
        return false;

        if(s[j1]==g[j2] && s[j2]==g[j1])
        return true;

        return 0;
    }
};