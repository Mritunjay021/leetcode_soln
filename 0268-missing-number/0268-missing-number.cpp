class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=0;

        for(int i=1;i<=nums.size();i++)
        n^=i;

        for(auto it:nums)
        {
            n^=it;
        }

        return n;
    }
};