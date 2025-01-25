class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) 
    {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        int c=0,d=0;

        for(int i=0;i<s1.length();i++)
        {
            if(s2[i]>=s1[i])
            c++;
            if(s2[i]<=s1[i])
            d++;
        }
        return (c==s1.length() || d==s1.length());

    }
};