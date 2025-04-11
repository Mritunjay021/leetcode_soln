class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int c=0;
        for(int i=low;i<=high;i++)
        {
            int s1=0,s2=0;
            string s=to_string(i);
            int l=s.length();

            if(l%2)
            continue;

            for(int j=0;j<l/2;j++)
            {
                s1+=s[j]-'0';
                s2+=s[l-j-1]-'0';
            }

            if(s1==s2)
            c++;
        }  

        return c;  
    }
};