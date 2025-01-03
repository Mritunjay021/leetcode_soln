class Solution {
public:

    bool func(string s,vector<string>& v,int j,vector<int> &dp)
    {
        if(dp[j]!=-1)
        return dp[j];

        if(j==s.length())
        return dp[j]=1;

        for(int i=0;i<v.size();i++)
        {
            if(s.substr(j,v[i].length())==v[i])
            {
                if(func(s,v,j+v[i].length(),dp))
                return dp[j]=1;
            }
        }
        return dp[j]=0;
    }

    bool wordBreak(string s, vector<string>& v) 
    {
        vector<int> dp(s.length()+1,-1);
        return func(s,v,0,dp);    
    }
};