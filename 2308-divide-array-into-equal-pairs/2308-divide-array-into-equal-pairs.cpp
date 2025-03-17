class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        vector<int> v(500,0);
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            v[nums[i]-1]++;
        }

        int c=0;

        for(int i=0;i<500;i++)
        {
            if(v[i]!=0 && v[i]%2)
            return 0;
        }

        return 1;
    }
};