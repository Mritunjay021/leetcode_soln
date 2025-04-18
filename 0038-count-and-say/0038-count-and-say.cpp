class Solution {
public:

    string func(int n)
    {
        if(n==1)
        return "1";

        string st=func(n-1);
        int ct=0;
        char ch=st[0];
        string s="";
        for(char c:st)
        {
            if(ch==c)
            ct++;
            else
            {
               s+=to_string(ct)+ch;
               ch=c;
               ct=1; 
            }
        }
        s+=to_string(ct)+ch;
        return s;
    }

    string countAndSay(int n) 
    {
        return func(n);
    }
};