class Solution {
public:
    int sumOfBeauties(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        vector<int> p(n,INT_MAX);
        vector<int> s(n,INT_MIN);
        p[0]=nums[0];
        s[n-1]=nums[n-1];
        for (int i = 1; i < n-1; i++) {
            p[i] = max(p[i - 1], nums[i-1]);
        }
        
        for (int i = n - 2; i > 0; i--) {
            s[i] = min(s[i + 1], nums[i+1]);
        } 

        // for(int i=0;i<n;i++)
        // cout<<s[i]<<endl; 

        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>p[i] && nums[i]<s[i])
            ans+=2;
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1])
            ans+=1;
        }
        return ans;
    }
};