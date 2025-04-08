class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        vector<int> v(101,0);

        for(auto it:nums)
        v[it]++;

        int j=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            while(v[nums[i]]>1)
            {
                c++;
                int k=3;
                while(j<nums.size() && k)
                {
                    v[nums[j++]]-=1;
                    k--;
                }
                
            }
        } 

        return c;   
    }
};