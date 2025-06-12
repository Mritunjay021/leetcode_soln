class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int n=nums.size();

        if(n==2)
        return abs(nums[0]-nums[1]);

        int mx=INT_MIN;

        mx=max(mx,max(abs(nums[0]-nums[1]),abs(nums[0]-nums[n-1])));

        for(int i=1;i<n-1;i++)
        {
            mx=max(mx,max(abs(nums[i]-nums[i+1]),abs(nums[i]-nums[i-1])));
        } 

        mx=max(mx,max(abs(nums[0]-nums[n-1]),abs(nums[n-2]-nums[n-1])));   

        return mx;
    }
};