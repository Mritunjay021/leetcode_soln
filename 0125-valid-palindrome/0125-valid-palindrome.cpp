class Solution {
public:
    bool func(int a,int b,const string &s)
    {
        if(a>=b) return true;   // base case
        return (s[a]==s[b]) && func(a+1,b-1,s);
    }

    bool isPalindrome(string s) 
    {
        string ns="";
        for(long i=0;i<s.length();i++)
        {
            if((s[i]>='a' && s[i]<='z') || 
               (s[i]>='A' && s[i]<='Z') || 
               (s[i]>='0' && s[i]<='9'))
                ns += (char)tolower((unsigned char)s[i]);
        }
   
        if(ns.length()<=1) return true;

        s=ns;
        cout << s << endl<<ns;

        int n = s.length();
        return (s[0]==s[n-1]) && func(1,n-2,s);    
    }
};
