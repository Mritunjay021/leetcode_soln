// class Solution {
// public:

//     int func(vector<int>& n,int i,int s,int mx)
//     {
//         if(i==n.size())
//         return mx;

//         s=max(n[i],s+n[i]);
        
//         mx=max(mx,s);

//         return func(n,i+1,s,mx);
//     }

//     int maxSubArray(vector<int>& n) 
//     {
//         int mx=INT_MIN;
//         return func(n,0,0,mx);
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int sum=0;
        int ans=INT_MIN;
        for(auto it:nums){
            sum+=it;
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
};