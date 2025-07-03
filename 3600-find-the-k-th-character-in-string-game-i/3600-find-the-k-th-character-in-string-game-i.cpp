class Solution {
public:
    char kthCharacter(int k) 
    {
        string s="a";

        while(k>s.length())
        {
            string str="";
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='z')
                str+='a';
                else
                str+=char(s[i]+1);
            }
            s+=str;
        }
        return s[k-1];
    }
};