class Solution {
public:
    int minMaxDifference(int num) 
    {
        string s = to_string(num);
        char ch;
        string a="",b="";

        for(char c:s)
        {
            if(c!='9')
            {
                ch=c;
                break;
            }
        }   

        for(char c:s)
        {
            if(c==ch)
            a+='9';
            else
            a+=c;
        }

        for(char c:s)
        {
            if(c==s[0])
            b+='0';
            else
            b+=c;
        }

        return stoi(a)-stoi(b);
    }
};