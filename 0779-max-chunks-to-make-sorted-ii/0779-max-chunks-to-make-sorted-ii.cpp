class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) 
    {
        vector<int> arr=nums;
        long long s1=0,s2=0,re=0;

        sort(arr.begin(),arr.end());

        for(int i=0;i<nums.size();i++)
        {
            s1+=nums[i];
            s2+=arr[i];

            if(s1==s2)
            re++;
        }
        return re;    
    }
};