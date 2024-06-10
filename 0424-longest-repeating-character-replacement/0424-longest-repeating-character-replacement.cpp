class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l=0,r=0,mf=0,mx=0;
        int hash[26]={0};
        while(r<s.length())
        {
            hash[s[r]-'A']++;
            mf=*(max_element(hash,hash+26));
            if((r-l+1-mf)<=k)
            mx=max(r-l+1,mx);
            else
            {
                hash[s[l]-'A']--;
                l++;
            }
            r++;
        }    
        return mx;
    }
};