class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int c=0;

        sort(nums.begin(),nums.end());

        vector<int> v(nums[nums.size()-1]+1,0);

        if(k>nums[0])
        return -1;

        for(auto it:nums)
        v[it]++;

        for(auto it:v)
        {
            if(it>0)
            c++;
        }    

        return v[k]>0?c-1:c;
    }
};