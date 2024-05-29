class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n=nums.size();
        int a;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                a=i;
                for(int j=i+1;j<n;j++)
                {
                    if(nums[j]!=0)
                    {
                        swap(nums[a],nums[j]);
                        break;
                    }
                }
                
            }
        }    
    }
};