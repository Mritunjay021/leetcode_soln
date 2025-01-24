class Solution {
public:
    void sortColors(vector<int>& nums) 
    { 
        int l=0,h=nums.size()-1,i=0;

        while(i<=h)
        {
            if(nums[i]==0 && i>=l)
            {
                swap(nums[i],nums[l++]);
                i--;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[h--]);
                i--;
            }
            i++;
        }
    }
};