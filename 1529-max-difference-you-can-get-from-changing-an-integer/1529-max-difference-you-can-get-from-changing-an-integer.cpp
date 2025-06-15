class Solution {
public:
    int maxDiff(int num) 
    {
        string s=to_string(num);

        if(s.length()==1)
        return 8;

        string a="",b="";
        char ca='0',cb='0';

        for(char c:s)
        {
            if(c!='9')
            {
                ca=c;
                break;
            }
        }

        for(char c:s)
        {
            if(c==ca)
            a+='9';
            else
            a+=c;
        }

        if(s[0]=='1')
        {
            for(int i=1;i<s.length();i++)
            {
                if(s[i]!='1' && s[i]!='0')
                {
                    cb=s[i];
                    break;
                }
            }    

            for(char c:s)
            {
                if(c==cb)
                b+='0';
                else
                b+=c;
            }
        }
        else
        {
            cb=s[0];
            for(char c:s)
            {
                if(c==cb)
                b+='1';
                else
                b+=c;
            }
        }

        if(b.length()==0)
        b=s;

        cout<<stoi(a)<<" "<<stoi(b);

        return stoi(a)-stoi(b);
    }
};