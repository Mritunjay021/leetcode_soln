class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;
        func(nums,0,n-1);
        func(nums,0,k-1);
        func(nums,k,n-1);    
    }

    void func(vector<int>& nums,int s,int e)
    {
        while(s<=e)
        {
            swap(nums[s++],nums[e--]);
        }
    }
};