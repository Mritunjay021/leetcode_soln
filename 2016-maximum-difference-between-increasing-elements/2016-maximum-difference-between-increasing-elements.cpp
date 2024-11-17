// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) 
//     {
//         int mx=-1;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[i]<nums[j])
//                 mx=max(mx,nums[j]-nums[i]);
//             }
//         }  
//         return mx;  
//     }
// };


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<2){
            return -1;
        }
        int maxDiff=-1;
        int left=0,right=1;
        while(right<n){
            if(nums[left]<nums[right]){
                maxDiff=max(maxDiff,nums[right]-nums[left]);
                right++;
            }
            else{
                left=right;
                right++;
            }
        }
        return maxDiff;
    }
};