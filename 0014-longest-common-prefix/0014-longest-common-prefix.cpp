class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
    int mn=INT_MAX,c=0;
    for(int i=1;i<strs.size();i++)
    {
        for(int j=0;j<strs[0].length();j++)
        {
            if(strs[0][j]!=strs[i][j])
            break;
            c++;
        }
        mn=min(mn,c);
        c=0;
    }   
    return strs[0].substr(0,mn);
    }
};