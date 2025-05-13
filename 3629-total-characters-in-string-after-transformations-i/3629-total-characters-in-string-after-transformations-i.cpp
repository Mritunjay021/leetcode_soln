class Solution {
public:

    int m=1e9+7;

    int lengthAfterTransformations(string s, int t) 
    {
        vector<int> fr(26,0);

        for(int i=0;i<s.length();i++)
        fr[s[i]-'a']++;

        for(int i=0;i<t;i++)
        {
            vector<int> temp(26,0);
            for(int j=0;j<26;j++)
            {
                if(fr[j]>0)
                {
                    if(j!=25)
                    temp[j+1]=fr[j];
                    else
                    {
                        temp[0]=(temp[0]+fr[j])%m;
                        temp[1]=(temp[1]+fr[j])%m;
                    }
                }
            }
            fr=temp;
        }    

        int sm=0;

        for(auto c:fr)
        sm=(sm+c)%m;

        return sm;
    }
};