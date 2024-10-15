class Solution {
public:
    long long maximumSubsequenceCount(string t, string p)
    {
        string t1=p[0]+t;
        string t2=t+p[1];
        long long a=0,re1=0,re2=0;
        for(int i=0;i<t1.length();i++)
        {
            if(t1[i]==p[0])
            a++;
            else if(t1[i]==p[1])
            re1+=a;
        }
        if(p[0]==p[1])
        {
            re1=((a)*(a-1))/2;
        }
        a=0;
        for(int i=0;i<t2.length();i++)
        {
            if(t2[i]==p[0])
            a++;
            else if(t2[i]==p[1])
            re2+=a;
        }
        if(p[0]==p[1])
        {
            re2=((a)*(a-1))/2;
        }
        return max(re1,re2);

    }
};