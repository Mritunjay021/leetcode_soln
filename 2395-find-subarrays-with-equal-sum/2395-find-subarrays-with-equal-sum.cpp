class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        map<int,int> mp;
        for(int i=0;i<nums.size()-1;i++)
        {
            mp[nums[i]+nums[i+1]]++;
        }
        for(auto it:mp)
        {
            if(it.second>1)
            return true;
        }
        return false;
            
    }
};