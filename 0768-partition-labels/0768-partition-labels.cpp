class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char,int> mp;
        vector<int> res;

        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]=i;
        }  

        int st=0,e=0;

        for(int i=0;i<s.length();i++)
        {
            e=max(e,mp[s[i]]);

            if(i==e)
            {
                res.push_back(e-st+1);
                e=0;
                st=i+1;
            }
        }

        return res;
    }
};