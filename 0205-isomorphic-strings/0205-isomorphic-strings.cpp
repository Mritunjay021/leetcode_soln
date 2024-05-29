class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        vector<pair<char,char>> p1;
        for(int i=0;i<s.length();i++)
        {
            p1.push_back({s[i],t[i]});
        } 
        bool r=true;   
        for(int i=1;i<p1.size();i++)
        {
            char c1=p1[i-1].first,c2=p1[i-1].second;
            for(int j=i;j<p1.size();j++)
            {
                if((c1==p1[j].first && c2!=p1[j].second) || (c1!=p1[j].first && c2==p1[j].second))
                return false;
            }
        }
        return r;
    }
};