class Solution {
public:

    void func(vector<int>& nums,set<vector<int>>& re,int k)
    {
        if(k==nums.size())
        {
            re.insert(nums);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            func(nums,re,k+1);
            swap(nums[i],nums[k]);
            func(nums,re,k+1);
            swap(nums[i],nums[k]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        set<vector<int>> re;
        func(nums,re,0);
        vector<vector<int>> v(re.begin(),re.end());
        return v;
    }
};