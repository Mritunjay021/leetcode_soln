class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        vector<int> v={0,0,0};

        int c=0,l=0,r=0;

        while(r<s.length())
        {
            v[s[r]-'a']++;

            while(l<=r && v[1]!=0 && v[2]!=0 && v[0]!=0)
            {
                c+=s.length()-r;
                v[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return c;
    }
};