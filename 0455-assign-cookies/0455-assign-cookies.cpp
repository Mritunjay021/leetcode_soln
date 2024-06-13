class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // Sort children's greed factors
        sort(s.begin(), s.end());  // Sort cookie sizes
        int contentChildren = 0;
        int i = 0;  // Index for children
        int j = 0;  // Index for cookies

        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                // Assign cookie j to child i
                contentChildren++;
                i++;  // Move to the next child
            }
            j++;  // Move to the next cookie
        }

        return contentChildren;
    }
};


/*
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        map<int,int> mp;
        int mn= INT_MAX,c=0;
        for(int i=0;i<g.size();i++)
        {
            int f=0;
            for(int j=0;j<s.size();j++)
            {
                if(g[i]<=s[j])
                {
                    mn=min(mn,s[j]);
                    c=j;
                    f=1;
                }
            }
            if(f)
            {
                mp[g[i]]=mn;
                s.erase(s.begin()+c);
            }
        }
        return mp.size();

    }
};
*/