class Solution {
public:
    bool lemonadeChange(vector<int>& ar) 
    {
        map<int,int> mp;
        for(int i=0;i<ar.size();i++)
        {
            if(ar[i]==5)
            mp[ar[i]]++;
            else if(ar[i]==10)
            {
                mp[ar[i]]++;
                if(mp[5]>0)
                mp[5]--;
                else
                return false;
            }
            else
            {
                if(mp[10]>0 && mp[5]>0)
                {
                    mp[10]--;mp[5]--;
                }
                else if(mp[5]>=3)
                {
                    mp[5]-=3;
                }
                else return false;
            }
        }    
        return true;
    }
};