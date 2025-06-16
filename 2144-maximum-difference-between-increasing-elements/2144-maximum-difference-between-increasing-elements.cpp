class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int n=nums.size();

        vector<int> v(n,-1);
        v[n-1]=n-1;

        int mx=-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[v[i+1]])
            v[i]=v[i+1];
            else
            v[i]=i;
        }    

        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[v[i]]-nums[i]);
        }        

        return mx==0?-1:mx;
    }
};