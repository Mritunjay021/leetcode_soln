class Solution {
public:

    int func(string st,int i,vector<int>& dp)
    {
        if(i==st.length())
        return 1;

        if(dp[i]!=-1)
        return dp[i];

        if(st[i]=='0')
        return 0;

        int w=func(st,i+1,dp);
        if(i+1<st.length() && stoi(st.substr(i,2))<=26)
        w+=func(st,i+2,dp);

        return dp[i]=w;

    }

    int numDecodings(string st) 
    {
        if(st[0]=='0')
        return 0;

        vector<int> dp(st.length(),-1);

        return func(st,0,dp);
    }
};