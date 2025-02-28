class Solution {
public:

    string ipv4(string st)
    {
        st+='.';
        int j=0;
        for(int i=0;i<st.length();i++)
        {
            if(st[i]=='.')
            {
                if(i-j<=3 && i-j>=1)
                {
                    if(i-j>1 && st[j]=='0')
                    return "Neither";

                    int num=0;
                    for(int k=j;k<i;k++)
                    {
                        if(st[k]<'0' || st[k]>'9')
                        return "Neither";

                        num=num*10+(st[k]-'0');
                    }

                    if(num>255)
                    return "Neither";

                    j=i+1;
                }
                else
                return "Neither";
                
            }
        }

        return "IPv4";
        
    }

    string ipv6(string st)
    {
        st+=':';
        int j=0;
        for(int i=0;i<st.length();i++)
        {
            if(st[i]==':')
            {
                if(i-j<=4 && i-j>=1)
                {
                    for(int k=j;k<i;k++)
                    {
                        if(!((st[k]>='0' && st[k]<='9') ||
                         (st[k]>='a' && st[k]<='f') || 
                        (st[k]>='A' && st[k]<='F')))
                        return "Neither";
                    }
                    j=i+1;
                }
                else
                return "Neither";
                
            }
        }

        return "IPv6";
    }

    string validIPAddress(string st) 
    {
        int p=0,t=0;
        for(int i=0;i<st.length();i++)
        {
            if(st[i]=='.')
            p++;
            else if(st[i]==':')
            t++;
        }    

        if(p==3)
        return ipv4(st);
        else if(t==7)
        return ipv6(st);
        return ("Neither");
    }
};