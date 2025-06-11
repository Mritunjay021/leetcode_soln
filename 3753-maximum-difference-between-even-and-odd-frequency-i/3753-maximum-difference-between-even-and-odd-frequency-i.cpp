class Solution {
public:
    int maxDifference(string s) 
    {
        vector<int> hash(26,0);

        for(int i=0;i<s.length();i++)
        {
            hash[s[i]-'a']++;
        }

        int mx=-1,mn=INT_MAX;

        for(int i=0;i<26;i++)
        {
            if(hash[i]>0)
            {
                if(hash[i]%2)
            mx=max(hash[i],mx);
            else
            mn=min(mn,hash[i]);
            }
        }

        return mx-mn;
    }
};