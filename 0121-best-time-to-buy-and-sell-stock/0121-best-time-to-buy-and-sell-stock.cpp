class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mn=prices[0],p=0;
        for(int i=0;i<prices.size();i++)
        {
            int c=prices[i]-mn;
            p=max(c,p);
            mn=min(mn,prices[i]);
        }    
        return p;
    }
};