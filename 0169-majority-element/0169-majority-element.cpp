class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int re=nums[0],c=1;

        for(int i=1;i<nums.size();i++)
        {
            if(c==0)
            re=nums[i];
            if(re==nums[i])
            c++;
            else
            c--;
        } 
        return re;
    }
};