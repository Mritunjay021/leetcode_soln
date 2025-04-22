class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        if(nums.size()==1)
        return 0;

        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=-1;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int m=sum%k;

            if(mp.find(m)!=mp.end())
            {
                if(i-mp[m]>1)
                return true;
            }
            else
            mp[m]=i;
        }   
        
        return false;
    }
};